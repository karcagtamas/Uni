var count = 2;

function refresh() {
    var sum = 0;
    $(".row").each(function () {
        var val = parseInt($(this).find(".result").val());
        sum += val;
    });

    var avg = (sum / count).toFixed(2);
    $(".avg").html(avg);
}

function add() {
    var row = $(".sample-row").clone(true, true);
    row.removeClass("sample-row");
    row.addClass("row");
    count++;
    row.find(".cc").html(count);
    $("table").append(row);
}

$(function () {
    $("select").on("change", function () {
        refresh();
    });

    $("button").on("click", function () {
        add();
    });
});

// TODO: prototype object