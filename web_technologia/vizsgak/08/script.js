var obj = [];
var lightTexts = ["Lámpa felkapcsolva.","Lámpa lekapcsolva."];
var img = "bulb.svg";
var alt = "izzó";
var click = 0;
var game = true;

$(function() {
    $("tr").each(function() {
        var row = [];
        $(this).find("td").each(function() {
            var src = $(this).find("img").attr("src");
            if (src && src == img) {
                row.push({izzo: true});
                $(this).find("img").addClass("light");
            }
            else {
                row.push({izzo: false});
            }
        });
        obj.push(row);
    });

    console.log(obj);
    $("td").on("click", function() {
        if (!game) {
            return;
        }
        click++;
        var id = parseInt($(this).attr("id"));

        var rowId = Math.floor(id / 5);
        var colId = id % 5;

        switchEl(rowId, colId);
        switchEl(rowId + 1, colId);
        switchEl(rowId - 1, colId);
        switchEl(rowId, colId + 1);
        switchEl(rowId, colId - 1);
        game = !checkStatus();
        if (!game) {
            alert("Gratuálok! Lépések: " + click);
        }
    });
});

function switchEl(rowId, colId) {
    if (rowId > 4 || rowId < 0 || colId > 4 || colId < 0) {
        return;
    }
    var el = obj[rowId][colId];
    var id = rowId * 5 + colId;
    if (el.izzo) {
        $(idToString(id)).attr("title", lightTexts[1]);
        $(idToString(id)).find("img").attr("src", null);
        $(idToString(id)).find("img").attr("alt", "");
        $(idToString(id)).find("img").removeClass("light");
    } else {
        $(idToString(id)).attr("title", lightTexts[0]);
        $(idToString(id)).find("img").attr("src", img);
        $(idToString(id)).find("img").attr("alt", alt);
        $(idToString(id)).find("img").addClass("light");
    }
    el.izzo = !el.izzo;
}

function idToString(id) {
    return "#"+id;
}

function checkStatus() {
    for (const i of obj) {
        for (const j of i) {
            if (j.izzo) {
                return false;
            }
        }
    }

    return true;
}