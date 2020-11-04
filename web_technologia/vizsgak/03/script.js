var freedays = 0;
const YEAR = 2019;

function generate() {
    'use strict'

    var month = 12;
    var days = 31;

    var table = $("table");

    for (var i = 0; i <= month; i++) {
        table.append("<tr>");
    }

    $("tr").each(function (index) {
        for (let i = 0; i <= days; i++) {
            if (index == 0) {
                var inside = i == 0 ? "" : i.toString();
                $(this).append("<th>" + inside + "</th>");
            } else if (i == 0) {
                $(this).append("<th>" + index + "</th>");
            } else {
                var date = new Date(YEAR, index - 1, i);
                var invalid = !validDate(date, YEAR, index - 1, i);
                var isNot = date.getDay() == 0 || date.getDay() == 6;
                if (invalid) {
                    $(this).append("<td></td>");
                } else if (isNot) {
                    $(this).append("<td class='not-work-day'></td>");
                } else {
                    $(this).append("<td class='work-day'>");
                }
            }
        }
    });

    $(".work-day").each(function () {
        $(this).on("click", function () {
            select($(this));
        });
    });
}

function select(obj) {
    if (obj.hasClass("selected")) {
        obj.removeClass("selected");
        freedays--;
    }
    else {
        obj.addClass("selected");
        freedays++;
    }

    $(".result").html(freedays);
}

function validDate(date, year, month, day) {
    console.log(year);
    console.log(month);
    console.log(day);
    return (date.getDate() == day && date.getMonth() == month && date.getFullYear() == year);
}

window.onload = generate;