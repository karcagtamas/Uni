window.addEventListener("load", getList);

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

  var selects = document.getElementsByTagName("select");
  for (const select of selects) {
    for (const i of list) {
      let option = document.createElement("option");
      option.value = i;
      option.text = i;
      select.appendChild(option);
    }
  }

  var form = document.getElementById("form");
  form.addEventListener("submit", (e) => {
    e.preventDefault();

    var from = document.getElementById("from").value;
    var to = document.getElementById("to").value;

    if (from == to) {
      alert("A két végpont megegyezik");
    } else {
      findResults(from, to);
    }
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
  let missed = document.getElementsByClassName("missed");
  let notMissed = document.getElementsByClassName("not-missed");
  for (const i of missed) {
    i.parentNode.removeChild(i);
  }
  for (const i of notMissed) {
    i.parentNode.removeChild(i);
  }

  for (const i of list) {
    var now = new Date();
    var isMissed = false;
    var hour = i.start.split(":")[0];
    var min = i.start.split(":")[1];

    if (now.getHours() > hour || now.getMinutes() > min) {
      isMissed = true;
    }

    let section = document.createElement("section");
    section.className += " " + (isMissed ? "missed" : "not-missed");
    let title = document.createElement("h3");
    title.innerHTML = i.vonat;
    let sp = document.createElement("p");
    sp.innerHTML = `Indulás: ${i.start}`;
    let fp = document.createElement("p");
    fp.innerHTML = `Érkezés: ${i.end}`;
    section.appendChild(title);
    section.appendChild(sp);
    section.appendChild(fp);

    let article = document.getElementById("article");
    article.appendChild(section);
  }
}
