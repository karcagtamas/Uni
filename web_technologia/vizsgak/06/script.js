$(function () {
    $("form").on("submit", function (e) {
        e.preventDefault();

        var m = [];

        $(this).find("tr").each(function () {
            var t = [];
            $(this).find("td").each(function () {
                t.push(parseInt($(this).find("input").val()));
            });
            m.push(t);
        });

        alert(isLatinSquare(m) ? "Ez egy latin négyzet" : "Ez nem egy latin négyzet")
    });
});

function isLatinSquare(m) {
    for (let i = 0; i < m.length; i++) {
        if (!checkRow(m[i])) {
            return false;
        }
    }

    var m2 = [];
    for (let i = 0; i < m.length; i++) {
        var t = [];
        for (let j = 0; j < m.length; j++) {
            t.push(m[j][i]);
        }
        m2.push(t);
    }

    for (let i = 0; i < m2.length; i++) {
        if (!checkRow(m2[i])) {
            return false;
        }
    }

    return true;
}

function checkRow(t) {
    var a = [];
    for (let i = 0; i < t.length; i++) {
        if (!a.includes(t[i])) {
            a.push(t[i]);
        }
    }

    return a.length == t.length;
}