var defImage = "web.png";
var texts = ["Kattintson a második kártya hátlapjára a megfordításához!", "Kattintson az első kártya hátlapjára a megfordításához! szöveget tartalmazza!"];
var foundText = "Megtalált egy kártyapárt!";
var foundAll = "Gratulálunk, Ön megtalálta az összes párt {0} fordítással!";
var notFoundText = "Nem egyeznek a kártyák, visszafordítjuk őket.";
var images = [
    {name: "html", image: "html5.png"},
    {name: "css", image: "css3.png"},
    {name: "js", image: "js.png"}
];
var obj = [
    { key: "p1" },
    { key: "p2" },
    { key: "p3" },
    { key: "p4" },
    { key: "p5" },
    { key: "p6" }
];
var found = 0;
var click = 0;


$(function() {
    $("img").on('click', function() {

        if ($(this).hasClass("selected") || $(this).hasClass("correct")) {
            return;
        }

        var id = $(this).attr("id");

        if (id) {
            var e = obj.find(x => x.key == id);

            if (e) {
                var selected = getNumberOfSelected();
                if (selected == 0) {
                    var image = images.find(x => x.name == e.imageName);
                    $(this).attr("src", image.image);
                    $(this).addClass("selected");
                    $(".info").html(texts[selected]);
                } else if(selected == 1) {
                    var image = images.find(x => x.name == e.imageName);
                    $(this).attr("src", image.image);
                    $(this).addClass("selected");
                    $(".info").html(texts[selected]);
                    click++;
                    checkSelectedValues();
                }
            }
        }
    });

    init();
});

function init() {
    var indexes = [0,1,2,3,4,5];

    for (let i = 0; i < 6; i++) {
        var random = Math.floor(Math.random() * indexes.length);
        var image = images[i % 3];
        obj[indexes[random]].imageName = image.name;
        indexes.splice(random, 1);
    }
}

function getNumberOfSelected() {
    return $(".selected").length;
}

function checkSelectedValues() {
    var ids = [];
    
    $(".selected").each(function() {
        ids.push($(this).attr("id"));
    });

    if (ids.length != 2) {
        return;
    }

    var first = obj.find(x => x.key == ids[0]);
    var second = obj.find(x => x.key == ids[1]);

    if (first && second && first.imageName == second.imageName) {
        found += 1;
        $(".selected").each(function() {
            $(this).addClass("correct");
            $(this).removeClass("selected");
        });
        $(".info").html(foundText);
        setTimeout(() => setBackToDefault(), 2000);
    }
    else {
        $(".info").html(notFoundText);
        setTimeout(() => setBackToDefault(), 2000);
    }
}

function setBackToDefault() {
    $(".selected").each(function() {
        $(this).attr("src", defImage);
        $(this).removeClass("selected");
    });
    if (found * 2 == obj.length) {
        var resText = foundAll.replace("{0}", click);
        $(".info").html(resText);
    }else {
        $(".info").html(texts[0]);
    }
}