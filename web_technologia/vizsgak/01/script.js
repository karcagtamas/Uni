function refresh() {
    var $a = $(".data");
    var $rows = $a.find(".row");
    $rows.each(function () {
        var zh1 = parseInt($(this).find(".zh1-input").val());
        var zh1pot = parseInt($(this).find(".zh1pot-input").val());
        var zh2 = parseInt($(this).find(".zh2-input").val());
        var zh2pot = parseInt($(this).find(".zh2pot-input").val());

        if (zh1 && zh2) {
            if (zh1pot && zh1pot > zh1) {
                zh1 = zh1pot;
            }
            if (zh2pot && zh2pot > zh2) {
                zh2 = zh2pot;
            }
            var summary = zh1 + zh2;
            console.log(summary);
            console.log($(this).find(".summary"));
            $(this).find(".summary").html(summary.toString());

            if (summary > 6) {
                $(this).find(".signed").html("Aláírva");
                $(this).find(".signed").addClass("accepted");
                $(this).find(".signed").removeClass("denied");
            } else {
                $(this).find(".signed").html("Megtagadva");
                $(this).find(".signed").addClass("denied");
                $(this).find(".signed").removeClass("accepted");
            }

            var mark = 0;
            if (summary >= 13) {
                mark = 5;
            } else if (summary >= 12) {
                mark = 4;
            } else if (summary >= 11) {
                mark = 3;
            }

            if (mark == 0) {
                $(this).find(".mark").html("");
                $(this).find(".mark").removeClass("good-mark");
            } else {
                $(this).find(".mark").html(mark);
                $(this).find(".mark").addClass("good-mark");
            }
        }
        else {
            $(this).find(".summary").html("");
            $(this).find(".mark").html("");
            $(this).find(".signed").html("");
        }
    });
}

$(function () {
    $("input.input").change(function () {
        refresh();
    });
});


function add() {
    var $clone = $(".sample-row").clone(true, true);
    $clone.removeClass("sample-row");
    $clone.addClass("row");
    $(".data").append($clone);
}

$(window).load(() => {
    add();
});