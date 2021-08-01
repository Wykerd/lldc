/**
 * Copyright 2021 Daniel Wykerd
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

/**
 * This generator is quite a mess but it works :-)
 * 
 * Feel free to improve it if you want to contribute!
 */

/**
 * Types: int, uint, toint, string, snowflake, timestamp, double
 * Structures: array, object
 */

const header = `/**
* Copyright 2021 Daniel Wykerd
*
* Use of this source code is governed by an MIT-style
* license that can be found in the LICENSE file or at
* https://opensource.org/licenses/MIT.
*/

/**
 * This source has been automatically generated.
 * Do not edit it directly!
 * 
 * See scripts/gen_parser.js and the schemas in schemas/
 * for the sources used to generate this file
 */`;

class SchemaParser {
    types = [];
    methods = [];
    signatures = [];
    enums = [];

    static getTableSize (entries)
    {
        return 1 << 32 - Math.clz32(entries / 0.7);
    }

    objString (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.string
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->${snakeCase(key)} = lldc_parser_strdup((lldc_parser_obj_t *)obj, yyjson_get_str(json));

    return 0;
}`)
    }

    objSnowflake (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.snowflake
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_get_str(json))
        return -1;

    obj->${snakeCase(key)} = (snowflake_t)atoll(yyjson_get_str(json));

    return 0;
}`)
    }

    enumGen (schema) {
        if (schema.enum) {
            if (schema.enum_def)
            {
                this.enums.push(schema.enum.map(e => {
                    return `/* ${e[2] ?? e[1]} */\n#define ${schema.enum_prefix}${snakeCase(e[1]).toUpperCase()} (${e[0]})`;
                }).join('\n'));
                return;
            }
            this.enums.push(`typedef enum lldc_${schema.enum_type} {
${
    schema.enum.map(e => {
        return `    /* ${e[2] ?? e[1]} */\n    ${schema.enum_prefix}${snakeCase(e[1]).toUpperCase()} = (${e[0]})`;
    }).join(',\n')
}
} lldc_${schema.enum_type}_t;`)
        }
    }

    objPrimative (key, schema, path, type) {
        this.enumGen(schema);
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.${type}
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_${type}(json))
        return -1;

    obj->${snakeCase(key)} = yyjson_get_${type}(json);

    return 0;
}`)
    }

    objTimestamp (key, schema, path) {
        this.enumGen(schema);
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.timestamp
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
    {
        obj->${snakeCase(key)} = NAN;
        return -1;
    }

    obj->${snakeCase(key)} = lldc_date_parse(yyjson_get_str(json));

    return 0;
}`)
    }

    objDouble (key, schema, path) {
        this.enumGen(schema);
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.double
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_real(json))
    {
        obj->${snakeCase(key)} = NAN;
        return -1;
    }

    obj->${snakeCase(key)} = yyjson_get_real(json);

    return 0;
}`)
    }

    objToUint (key, schema, path) {
        this.enumGen(schema);
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.touint
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_str(json))
        return -1;

    obj->${snakeCase(key)} = (uint64_t)atoll(yyjson_get_str(json));

    return 0;
}`)
    }

    objRawObj (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.rawobj
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_obj(json))
        return -1;

    obj->${snakeCase(key)} = json;

    return 0;
}`)
    }

    rawJson (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.rawobj
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    obj->${snakeCase(key)} = json;

    return 0;
}`)
    }

    arrRawObj (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: object.rawarr
 */
static
int lldc__${[...path, snakeCase(key)].join('_')}_parse (lldc_${path.join('_')}_t *obj, yyjson_val *json) 
{
    if (!yyjson_is_arr(json))
        return -1;

    obj->${snakeCase(key)} = json;

    return 0;
}`)
    }

    objTypeGen (schema, path, keys, isRoot = false) {
        this.types.push(
`/* ${schema.description.replace(/\n/g, '\n * ')} */
typedef struct lldc_${path.join('_')}_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;${
        isRoot ? `
    lldc_parser_malloc_ledger_t __mlog;` : ''
    }
    ${
        keys.map(key => {
            let typedef = `/** 
     * ${schema.properties[key].description.replace(/\n/g, '\n     * ')} 
     */\n    `;
            switch (schema.properties[key].type) {
                case 'toint':
                case 'uint':
                    typedef += 
                        schema.properties[key].enum_type ? 
                            `lldc_${schema.properties[key].enum_type}_t ` :
                            'uint64_t ';
                    break;

                case 'snowflake':
                    typedef += 'snowflake_t ';
                    break;

                case 'timestamp':
                case 'double':
                    typedef += 'double ';
                    break;

                case 'int':
                case 'boolean':
                    typedef += 
                        schema.properties[key].enum_type ? 
                            `lldc_${schema.properties[key].enum_type}_t ` :
                            'int ';
                    break;

                case 'string':
                    typedef += 'const char *';
                    break;

                case 'raw':
                    typedef += 'yyjson_val *';
                    break;

                case 'object':
                    {
                        if (schema.properties[key].properties)
                            typedef += `lldc_${[...path, snakeCase(key)].join('_')}_t `
                        else if (schema.properties[key].existing_parser)
                            typedef += `lldc_${schema.properties[key].existing_parser}_t `
                        else
                            typedef += 'yyjson_val *'
                    }
                    break;

                case 'array':
                    {
                        if (schema.properties[key].existing_parser)
                            typedef += `lldc_${schema.properties[key].existing_parser}_t `
                        else if (schema.properties[key].items)
                            typedef += `lldc_${[...path, snakeCase(key)].join('_')}_arr_t `
                        else
                            typedef += 'yyjson_val *'
                    }
                    break;
            
                default:
                    typedef += '// ';
                    break;
            }
            typedef += snakeCase(key);
            typedef += ';';
            return typedef;
        }).join('\n    ')
    }
} lldc_${path.join('_')}_t;`
        )
    }

    arrTypeGen (schema, path, isRoot) {
        let typedef = '';
        if (schema.items.type == 'array')
            switch (schema.items.items.type) {
                case 'uint':
                case 'snowflake':
                case 'int':
                case 'toint':
                case 'boolean':
                case 'string':
                case 'double':
                case 'timestamp':
                    typedef = `lldc_parser_${schema.items.items.type}_arr_t `;
                    break;

                case 'array':
                    typedef = `lldc_${(schema.items.existing_parser ? [schema.items.existing_parser] : [...path, 'item_arr']).join('_')}_t `;
                    break;

                default:
                    typedef = '// ';
                    break;
            }
        this.types.push(
`/* ${schema.description.replace(/\n/g, '\n * ')} */
typedef struct lldc_${path.join('_')}_arr_s {
    cwr_malloc_ctx_t *_mctx;
    lldc_parser_malloc_ledger_t *_mlog;
    ${
        schema.items.type == 'raw' ?
            'yyjson_val *' :
        schema.items.type == 'object' ? 
            schema.items.properties ?
                `lldc_${[...path, 'item'].join('_')}_t `:
            schema.items.existing_parser ?
                `lldc_${schema.items.existing_parser}_t ` :
                `yyjson_val *` :
            typedef 
    }*items;
    size_t len;${
        isRoot ? `
    lldc_parser_malloc_ledger_t __mlog;` : ''
    }
} lldc_${path.join('_')}_arr_t;`);
    }

    arrImpl (key, schema, path, isRoot = false, wantMallocSetters = true) {
        this.arrElement(key, schema.items, path);
        this.arrTypeGen(schema, path, isRoot);
        return `
    if (!yyjson_is_arr(json))
        return -1;

    size_t arr_size = yyjson_arr_size(json);
    if (!arr_size)
    {
        obj->items = NULL;
        obj->len = 0;
        return 0;
    }

    ${isRoot ? 
    `obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
` : wantMallocSetters ? `obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
` : ``
    }
    obj->items = lldc_parser_malloc((lldc_parser_obj_t *)obj, sizeof(*obj->items) * arr_size);
    if (obj->items == NULL)
    {
        obj->len = 0;
        return -1;
    }
    obj->len = arr_size;

    size_t idx, max;
    yyjson_val *val;
    yyjson_arr_foreach(json, idx, max, val) {
        obj->items[idx]._mctx = obj->_mctx;
        obj->items[idx]._mlog = obj->_mlog;
        lldc__${path.join('_')}_item_parse(&obj->items[idx], val);
    }

    return 0;`
    }

    objImpl (key, schema, path, keys, isRoot = false, wantMallocSetters = true) {
        const table_size = SchemaParser.getTableSize(keys.length);

        this.objTypeGen(schema, path, keys, isRoot);

        return `
    static lldc_parser_def_t parser_def[${keys.length}] = {
        ${
            keys.map(key => 
                `{ ${JSON.stringify(key)}, (int (*)(void *, yyjson_val *))lldc__${[...path, snakeCase(key)].join('_')}_parse }`    
            ).join(',\n        ')
        }
    };

    static lldc_hashmap_entry_t parser_table[${table_size}] = { 0 };
    static lldc_hashmap_t parsers = {  
        .size = ${table_size},
        .len = 0,
        .table = parser_table,
        .hash = lldc_hashmap_hash_str,
        .compare = (int (*)(const void *, const void *))strcmp,
        .dup_key = lldc_hashmap_dup_echo,
        .free_key = lldc_hashmap_free_noop
    };
    LLDC_PARSER_LOAD(${keys.length})

    if (!yyjson_is_obj(json))
        return -1;

    lldc_parser_malloc_ledger_t *ledger = obj->_mlog;
    ${!wantMallocSetters ? 'cwr_malloc_ctx_t *mctx = obj->_mctx;' : ''}
    memset(obj, 0, sizeof(lldc_${path.join('_')}_t));

    ${isRoot ? 
    `obj->_mctx = _mctx;
    if (!has_existing_ledger)
        obj->_mlog = &obj->__mlog;
    else
        obj->_mlog = ledger;
` : wantMallocSetters ? `obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
` : `obj->_mlog = ledger;
    obj->_mctx = mctx;`
    }
    yyjson_val *key, *val;
    yyjson_obj_iter iter;
    yyjson_obj_iter_init(json, &iter);
    while ((key = yyjson_obj_iter_next(&iter))) {
        val = yyjson_obj_iter_get_val(key);
        lldc_parser_func parser = lldc_hashmap_get(&parsers, yyjson_get_str(key));
        if (parser)
            parser(obj, val);
    }

    return 0;`
    }

    objAdapter (key, schema, o_path) {
        const path = [...o_path, snakeCase(key)];

        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: object.object
*/
static
int lldc__${path.join('_')}_parse (lldc_${o_path.join('_')}_t *_obj, yyjson_val *json)
{
    _obj->${snakeCase(key)}._mlog = _obj->_mlog;
    return lldc_${schema.existing_parser}_parse(_obj->_mctx, &_obj->${snakeCase(key)}, json, 1);
}`);
    }

    arrAdapter (key, schema, o_path) {
        const path = [...o_path, snakeCase(key)];

        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: object.object
*/
static
int lldc__${path.join('_')}_parse (lldc_${o_path.join('_')}_t *_obj, yyjson_val *json)
{
    _obj->${snakeCase(key)}._mlog = _obj->_mlog;
    return lldc_${schema.existing_parser}_parse(_obj->_mctx, &_obj->${snakeCase(key)}, json, 1);
}`);
    }

    objNest (key, schema, o_path) {
        const path = [...o_path, snakeCase(key)];

        const keys = Object.keys(schema.properties);

        keys.forEach(key => {
            this.objChild(key, schema.properties[key], path)
        });

        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: object.object
*/
static
int lldc__${path.join('_')}_parse (lldc_${o_path.join('_')}_t *_obj, yyjson_val *json)
{
    lldc_${path.join('_')}_t *obj = &_obj->${snakeCase(key)};
${this.objImpl(key, schema, path, keys, false)}
}`);
    }

    objArrNest (key, schema, o_path) {
        const path = [...o_path, 'item'];

        const keys = Object.keys(schema.properties);

        keys.forEach(key => {
            this.objChild(key, schema.properties[key], path)
        });

        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: array.object
*/
static
int lldc__${o_path.join('_')}_item_parse (lldc_${o_path.join('_')}_item_t *obj, yyjson_val *json)
{
${this.objImpl(key, schema, path, keys, false, false)}
}`);
    }

    arrNest (key, schema, o_path) {
        const path = [...o_path, snakeCase(key)];

        let impl = `
    obj->_mctx = _obj->_mctx;
    obj->_mlog = _obj->_mlog;
    return lldc_parser_${schema.items.type}_arr_parse(obj, json);`;
        let type = `parser_${schema.items.type == 'toint' ? 'uint': schema.items.type}`;

        switch (schema.items.type) {
            case 'object':
            case 'array':
                impl = this.arrImpl(key, schema, path, false, true);
                type = path.join('_');
                break;
        }

        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: object.array[${schema.items.type}]
*/
static
int lldc__${path.join('_')}_parse (lldc_${o_path.join('_')}_t *_obj, yyjson_val *json)
{
    lldc_${type}_arr_t *obj = &_obj->${snakeCase(key)};
${impl}
}`);
    }

    arrArrNest (key, schema, path) {
        const n_path = [...path, 'item'];

        let impl = `lldc_parser_${schema.items.type}_arr_parse(obj, val)`;
        let type = `parser_${schema.items.type}`;

        switch (schema.items.type) {
            case 'object':
            case 'array':
                impl = this.arrImpl(key, schema, n_path, false, false);
                type = n_path.join('_');
                break;
            default:
                this.signatures.push(`#define lldc__${path.join('_')}_item_parse(obj, val) ${impl}`);
                return; 
        }
        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: array.array[${schema.items.type}]
*/
static
int lldc__${path.join('_')}_item_parse (lldc_${type}_arr_t *obj, yyjson_val *json)
{
${impl}
}`);
    }

    objArrAdapter (key, schema, path) {
        this.methods.push(
`/**
* ${key} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
* type: object.object
*/
static
int lldc__${path.join('_')}_item_parse (lldc_${schema.existing_parser}_t *_obj, yyjson_val *json)
{
    return lldc_${schema.existing_parser}_parse(_obj->_mctx, _obj, json, 1);
}`);
    }

    objArrRawObj (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: array.rawobj
 */
static inline
int lldc__${path.join('_')}_item_parse (yyjson_val **_obj, yyjson_val *json)
{
    if (!yyjson_is_obj(json))
        return -1;

    *_obj = json;

    return 0;
}`)
    }

    rawArrRawObj (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: array.rawobj
 */
static inline
int lldc__${path.join('_')}_item_parse (yyjson_val **_obj, yyjson_val *json)
{
    *_obj = json;

    return 0;
}`)
    }

    arrArrRawObj (key, schema, path) {
        this.methods.unshift(
`/**
 * ${key} Parser
 * ${schema.description.replace(/\n/g, '\n * ')}
 * type: array.rawarr
 */
static inline
int lldc__${path.join('_')}_item_parse (yyjson_val **_obj, yyjson_val *json)
{
    if (!yyjson_is_arr(json))
        return -1;

    *_obj = json;

    return 0;
}`)
    }

    arrArrAdapter (key, schema, path) {
        return this.objArrAdapter(key, schema, path);
    }

    arrElement (key, schema, path) {
        console.log('arrEl', schema, key);
        switch (schema.type) {
            case 'uint':
            case 'int':
            case 'double':
            case 'timestamp':
            case 'toint':
            case 'snowflake':
            case 'string':
            case 'boolean':
                throw new Error('Unreachable!');

            case 'object':
                {
                    if (schema.properties)
                        return this.objArrNest(key, schema, path);
                    else if (schema.existing_parser)
                        return this.objArrAdapter(key, schema, path);
                    else
                        return this.objArrRawObj(key, schema, path);
                }

            case 'raw':
                return this.rawArrRawObj(key, schema, path);

            case 'array':
                {
                    if (schema.items)
                        return this.arrArrNest(key, schema, path);
                    else if (schema.existing_parser)
                        return this.arrArrAdapter(key, schema, path);
                    else
                        return this.arrArrRawObj(key, schema, path);
                }
        
            default:
                break;
        }
    }

    objChild (key, schema, path) {
        console.log('objChild', schema, key);
        switch (schema.type) {
            case 'uint':
            case 'int':
                return this.objPrimative(key, schema, path, schema.type);

            case 'double':
                return this.objDouble(key, schema, path);
            
            case 'timestamp':
                return this.objTimestamp(key, schema, path);

            case 'toint':
                return this.objToUint(key, schema, path);

            case 'snowflake':
                return this.objSnowflake(key, schema, path, schema.type);

            case 'string':
                return this.objString(key, schema, path);

            case 'boolean':
                return this.objPrimative(key, schema, path, 'bool');

            case 'object':
                {
                    if (schema.properties)
                        return this.objNest(key, schema, path);
                    else if (schema.existing_parser)
                        return this.objAdapter(key, schema, path);
                    else
                        return this.objRawObj(key, schema, path);
                }

            case 'raw':
                return this.rawJson(key, schema, path);

            case 'array':
                {
                    if (schema.items)
                        return this.arrNest(key, schema, path);
                    else if (schema.existing_parser)
                        return this.arrAdapter(key, schema, path);
                    else
                        return this.arrRawObj(key, schema, path);
                }
        
            default:
                break;
        }
    }

    obj (key, schema, o_path, isRoot = false) {
        const path = [...o_path, snakeCase(key)];

        const keys = Object.keys(schema.properties);

        keys.forEach(key => {
            this.objChild(key, schema.properties[key], path)
        });

        this.signatures.push(`/**
* ${schema.title} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
*/
int lldc_${path.join('_')}_parse (cwr_malloc_ctx_t *_mctx, lldc_${path.join('_')}_t *obj, yyjson_val *json, int has_existing_ledger);`);

        this.methods.push(`int lldc_${path.join('_')}_parse (cwr_malloc_ctx_t *_mctx, lldc_${path.join('_')}_t *obj, yyjson_val *json, int has_existing_ledger)
{
${this.objImpl(key, schema, path, keys, isRoot)}
}`);
    }

    arr (key, schema, o_path, isRoot = false) {
        const path = [...o_path, snakeCase(key)];

        this.signatures.push(`/**
* ${schema.title} Parser
* ${schema.description.replace(/\n/g, '\n * ')}
*/
int lldc_${path.join('_')}_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_${path.join('_')}_arr_t *obj, yyjson_val *json, int has_existing_ledger);`);

        this.methods.push(`int lldc_${path.join('_')}_arr_parse (cwr_malloc_ctx_t *_mctx, lldc_${path.join('_')}_arr_t *obj, yyjson_val *json, int has_existing_ledger)
{
${this.arrImpl(key, schema, path, isRoot)}
}`);
    }

    parse(schema) {
        switch (schema.type) {
            case 'object':
                return this.obj(schema.title, schema, [], true);

            case 'array':
                return this.arr(schema.title, schema, [], true);
        
            default:
                throw new Error('Expected "object" or "array" as root type');
        }
    }
}

const fs = require('fs');
const path = require('path');
const snakeCase = require('./snakecase');
const files = require('../schemas/index.json');

const parser = new SchemaParser();

files.forEach(filename => {
    const schema = JSON.parse(fs.readFileSync(path.resolve(__dirname, '..', 'schemas', filename), 'utf8'));

    parser.parse(schema);
});

fs.writeFileSync(
    path.resolve(__dirname, '..', 'include', 'lldc', 'parsers.h'), 
    [
        header,
        '#ifndef LLDC_PARSERS_H',
        '#define LLDC_PARSERS_H',
        '#include <lldc/parse.h>',
        '#include <yyjson.h>',
        ...parser.enums, 
        ...parser.types, 
        ...parser.signatures,
        '#endif'
    ].join('\n')
);

fs.writeFileSync(
    path.resolve(__dirname, '..', 'src', 'parsers.c'), 
    [
        header,
        '#include <lldc/parsers.h>',
        '#include <lldc/hashmap.h>',
        '#include <stdlib.h>',
        ...parser.methods,
    ].join('\n')
)

// Quick and simple export target #table_id into a csv
function enum_from_table (table_id) {
    // Select rows from table_id
    var rows = document.querySelectorAll('table#' + table_id + ' tr');
    // Construct csv
    var csv = [];
    for (var i = 0; i < rows.length; i++) {
        var row = [], cols = rows[i].querySelectorAll('td, th');
        for (var j = 0; j < cols.length; j++) {
            var data = cols[j].innerText.replace(/(\r\n|\n|\r)/gm, '').trim();
            row.push(data);
        }
        csv.push([row[1].split('(').pop().replace(/(\(|\))/g, ''), row[0].replace(/\*/g, '').trim(), row[2]]);
    }
    csv.shift();
    console.log(JSON.stringify(csv, null, '  '))
}

function structure_boiler (table_id) {
    // Select rows from table_id
    var rows = document.querySelectorAll('table#' + table_id + ' tr');
    var properties = {};
    for (var i = 0; i < rows.length; i++) {
        var row = [], cols = rows[i].querySelectorAll('td, th');
        for (var j = 0; j < cols.length; j++) {
            var data = cols[j].innerText.replace(/(\r\n|\n|\r)/gm, '').trim();
            row.push(data);
        }
        let optional = false;
        let field = row[0].replace(/\*/g, '').trim();
        if (field.includes('?'))
        {
            optional = true;
            field = field.replace(/\?/g, '');
        };
        let type = row[1].replace(/\*/g, '').trim();
        if (type.includes('?'))
        {
            optional = true;
            type = type.replace(/\?/g, '');
        };
        let description = optional ? 'OPTIONAL: ' + row[2] : row[2];
        if (type === 'integer')
        {
            type = 'int';
        };
        properties[field] = {
            description,
            type
        }
    }
    console.log(JSON.stringify(properties, null, '    '))
}
