var obj = [];
var lightTexts = ["Lámpa felkapcsolva.", "Lámpa lekapcsolva."];
var img = "bulb.svg";
var alt = "izzó";
var click = 0;
var game = true;

window.addEventListener("load", gen);

function gen() {
  let trList = document.getElementsByTagName("tr");

  for (const tr of trList) {
    var row = [];
    let tdList = tr.getElementsByTagName("td");
    for (const td of tdList) {
      let src = td.getElementsByTagName("img").item(0).src;
      if (src && src.includes(img)) {
        row.push({ izzo: true });
        td.getElementsByTagName("img").item(0).className += " light";
      } else {
        row.push({ izzo: false });
      }
    }
    obj.push(row);
  }

  let tdList = document.getElementsByTagName("td");
  for (const td of tdList) {
    td.addEventListener("click", tdClick);
  }
}

function tdClick(e) {
  if (!game) {
    return;
  }
  let el = e.srcElement;
  click++;
  let id = parseInt(el.id);

  if (!id) {
    id = parseInt(el.parentNode.id);
  }

  let rowId = Math.floor(id / 5);
  let colId = id % 5;

  switchEl(rowId, colId);
  switchEl(rowId + 1, colId);
  switchEl(rowId - 1, colId);
  switchEl(rowId, colId + 1);
  switchEl(rowId, colId - 1);
  game = !checkStatus();
  if (!game) {
    alert(`Gratulálok! Lépések: ${click}.`);
  }
}

function switchEl(rowId, colId) {
  if (rowId > 4 || rowId < 0 || colId > 4 || colId < 0) {
    return;
  }

  let el = obj[rowId][colId];
  let id = rowId * 5 + colId;
  let htmlEl = document.getElementById(id);
  let htmlElImg = htmlEl.getElementsByTagName("img").item(0);
  if (el.izzo) {
    htmlEl.title = lightTexts[1];
    htmlElImg.src = "";
    htmlElImg.alt = "";
    htmlElImg.className = htmlElImg.className.replace("light", "");
  } else {
    htmlEl.title = lightTexts[0];
    htmlElImg.src = img;
    htmlElImg.alt = alt;
    htmlElImg.className += " light";
  }
  el.izzo = !el.izzo;
}

function idToString(id) {
  return `#${id}`;
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
