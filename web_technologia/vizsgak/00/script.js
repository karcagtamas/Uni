const teachers = [];

window.addEventListener("load", init);

function init() {
  /*let dataRows = document.getElementsByClassName("data");

  for (const data of dataRows) {
    let name = data.getElementsByClassName("oktato").item(0).innerHTML;

    teachers.push({ name, lessons });
  }

  console.log(teachers);*/

  let inputs = document.getElementsByTagName("input");
  for (const input of inputs) {
    input.addEventListener("change", valChange);
  }
}

function valChange(e) {
  rowRefresh(e.srcElement);
  colRefresh();
}

function rowRefresh(element) {
  let parent = element.parentElement.parentElement;
  let inputs = parent.getElementsByTagName("input");
  let sum = 0;

  for (const i of inputs) {
    sum += i.value ? parseInt(i.value) : 0;
  }

  let result = parent.getElementsByClassName("row-result").item(0);
  result.innerHTML = sum;
}

function colRefresh() {
  let rows = document.getElementsByClassName("data");
  let t = [];
  let tSums = [];

  for (const i of rows) {
    let inputs = i.getElementsByTagName("input");

    let row = [];
    let rowSum = 0;
    for (const k of inputs) {
      let val = k.value ? parseInt(k.value) : 0;
      row.push(val);
      rowSum += val;
    }
    t.push(row);
    tSums.push(rowSum);
  }

  let resRow = document.getElementById("result-row");
  let resCols = resRow.getElementsByClassName("col-result");

  for (let i = 0; i < resCols.length; i++) {
    let sum = 0;
    for (let j = 0; j < t.length; j++) {
      sum += t[j][i];
    }
    resCols.item(i).innerHTML = sum ? sum : 0;
  }

  let index = -1;
  if (tSums[0] >= tSums[1] * 2) {
    index = 0;
  } else if (tSums[1] >= tSums[0] * 2) {
    index = 1;
  }

  for (let i = 0; i < rows.length; i++) {
    let nameField = rows.item(i).getElementsByClassName("oktato").item(0);

    nameField.className = nameField.className.replace("selected", "");

    if (i == index) {
      nameField.className += " selected";
    }
  }
}
