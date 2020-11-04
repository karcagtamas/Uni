$(window).on("load", function () {
    summary();
});

$(function () {

    $(".p").change(function () {
        summary();
    });
});

function summary() {
    'use strict'
    var summary = 0;
    $(".p").each(function () {
        summary += parseInt($(this).val());
    });

    var mark = getMark(summary);

    var markString = "elégtelen";

    switch (mark) {
        case 5:
            markString = "jeles";
            break;
        case 4:
            markString = "jó";
            break;
        case 3:
            markString = "közepes";
            break;
        case 2:
            markString = "elégséges";
            break;
    }

    $(".summary").html(mark);
    $(".mark").html(markString + " (" + mark + ")");

}

function getMark(points) {
    if (points >= 45) {
        return 5;
    } else if (points >= 38) {
        return 4;
    } else if (points >= 31) {
        return 3;
    } else if (points >= 26) {
        return 2;
    }

    return 1;
}