var obj = [];
var last;

$(function () {
    $("form").on("submit", function (e) {
        e.preventDefault();
        var rendszam = $("#rendszam").val();
        var date = new Date($("#date").val());
        var status = parseInt($("#status").val());
        try {
            addStatus(rendszam, date, status);
        }
        catch (e) {
            alert(e);
        }
    });
});

function addStatus(rendszam, date, status) {
    var found = obj.find(x => x.rendszam == rendszam);
    if (!found) {
        obj.push({ rendszam: rendszam, statuses: [{ status: status, date: date }] });
        $("#list").append("<option>" + rendszam + "</option>");
        $("ol").html("");
        $("ol").append("<li>" + status + "</li>");
    }
    else {
        found.statuses.push({ date: date, status: status });

        if (last.rendszam == found.rendszam) {
            $("ol").append("<li>" + status + "</li>");
        }
        else {
            $("ol").html("");
            for (let i = 0; i < found.statuses.length; i++) {
                $("ol").append("<li>" + found.statuses[i].status + "</li>");
            }
        }
    }

    last = obj.find(x => x.rendszam == rendszam);
    if (found && found.statuses[found.statuses.length - 2].status > status) {
        throw "Valószínű a csalás az órákban. (Kisebb mint az utolsó)";
    }
}