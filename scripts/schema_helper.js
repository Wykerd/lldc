/**
 * Paste into console while using developer docs.
 * Click on a table and convert it to a bare bones schema
 */

function enum_from_table2 (table) {
    // Select rows from table_id
    var rows = table.querySelectorAll('tr');
    // Construct csv
    var enums = [];
    for (var i = 0; i < rows.length; i++) {
        var row = [], cols = rows[i].querySelectorAll('td, th');
        for (var j = 0; j < cols.length; j++) {
            var data = cols[j].innerText.replace(/(\r\n|\n|\r)/gm, '').trim();
            row.push(data);
        }
        enums.push([row[0].split('(').pop().replace(/(\(|\))/g, ''), row[1].replace(/\*/g, '').trim()]);
    }
    enums.shift();
    console.log('enum');
    console.log(JSON.stringify(enums, null, '    '))
}

function enum_from_table1 (table) {
    // Select rows from table_id
    var rows = table.querySelectorAll('tr');
    // Construct csv
    var enums = [];
    for (var i = 0; i < rows.length; i++) {
        var row = [], cols = rows[i].querySelectorAll('td, th');
        for (var j = 0; j < cols.length; j++) {
            var data = cols[j].innerText.replace(/(\r\n|\n|\r)/gm, '').trim();
            row.push(data);
        }
        enums.push([row[1].split('(').pop().replace(/(\(|\))/g, ''), row[0].replace(/\*/g, '').trim(), row[2]]);
    }
    enums.shift();
    console.log('enum');
    console.log(JSON.stringify(enums, null, '    '))
}

globalThis.enum_from_table = enum_from_table1;

function structure_boiler (table) {
    // Select rows from table_id
    var rows = table.querySelectorAll('tr');
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
        if (type.toLowerCase() == 'iso8601 timestamp')
        {
            type = 'timestamp';
        }
        properties[field] = {
            description,
            type
        }
    }
    console.log('structure');
    delete properties.FIELD;
    console.log(JSON.stringify(properties, null, '    '))
}

document.querySelectorAll('table').forEach(table => {
    table.addEventListener('click', () => {
        enum_from_table(table);
        structure_boiler(table);
    });
})