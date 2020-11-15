$(function () {
  getList();
});

function getList() {
  var list = [];

  for (const key in adatbazis) {
    if (adatbazis.hasOwnProperty(key)) {
      const element = adatbazis[key];
      for (const i of element) {
        if (!list.includes(i.megallo)) {
          list.push(i.megallo);
        }
      }
    }
  }

  $("select").each(function () {
    for (const i of list) {
      $(this).append(`<option>${i}</option>`);
    }
  });

  $("form").on("submit", function (e) {
    e.preventDefault();
    var from = $("#from").val();
    var to = $("#to").val();

    if (from == to) {
      alert("A két végpont megegyezik!");
    }

    findResults(from, to);
  });
}

function findResults(from, to) {
  var list = [];
  for (const key in adatbazis) {
    if (adatbazis.hasOwnProperty(key)) {
      const element = adatbazis[key];
      var fromIndex = element.findIndex((x) => x.megallo == from);
      var toIndex = element.findIndex((x) => x.megallo == to);

      if (fromIndex != -1 && toIndex != -1 && fromIndex < toIndex) {
        list.push({
          vonat: key,
          start: element[fromIndex].indul,
          end: element[toIndex].erkezik,
        });
      }
    }
  }
  writeResults(list);
}

function writeResults(list) {
  $(".missed").each(function () {
    $(this).remove();
  });
  $(".not-missed").each(function () {
    $(this).remove();
  });

  for (const i of list) {
    var now = new Date();
    var missed = false;
    var hour = i.start.split(":")[0];
    var min = i.start.split(":")[1];

    if (now.getHours() > hour || now.getMinutes() > min) {
      missed = true;
    }
    var text = `<section class="${missed ? "missed" : "not-missed"}"><h3>${
      i.vonat
    }</h3> <p>Indulás: ${i.start}</p><p>Érkezés: ${i.end}</p></section>`;

    $("article").append(text);
  }
}
