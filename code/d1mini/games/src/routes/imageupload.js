async function post_www_url_encoded(data) {
  const body = new URLSearchParams();
  for (let key in data) {
    body.append(key, data[key]);
  }
  return await fetch('/command', { method: "POST", body });
}


function handleFiles() {
  //const fileList = this.files; /* now you can work with the file list */
  //const pbmfile = fileList[0];
  const pbmfile = document.getElementById('input').files[0];
  console.log(pbmfile.name);
  console.log(pbmfile.size);
  const reader = new FileReader();
  reader.addEventListener('loadend', async () => {
    console.log(reader.result);
    const rawbuffer = new Uint8Array(reader.result);
    console.log(rawbuffer);
    /*
    for (let i = 8; i < pbmfile.size ; i++) {
      console.log(rawbuffer[i]);
    }
    */
    let startofWidth = 3;
    let newlinecounter = 0;
    if (rawbuffer[startofWidth] === 0x23) {
      for (let i = 0; i < pbmfile.size; i++) {
        if (rawbuffer[i] === 0x0A) {
          newlinecounter = newlinecounter + 1;
        }
        if (newlinecounter === 2) {
          if (rawbuffer[i + 1] === 0x0A) {
            startofWidth = i + 2;
          }

          else {
            startofWidth = i + 1;
          }

          break;
        }
      }
    }
    const width1 = rawbuffer[startofWidth];
    const width2 = rawbuffer[startofWidth + 1];
    let width = 10 * (width1 - 0x30) + (width2 - 0x30);
    console.log("width:", width);
    let column = 0;
    let row = 0;
    let startDataIndex;

    for (let k = startofWidth + 1; k < pbmfile.size; k++) {
      if (rawbuffer[k] === 0x0A) {
        startDataIndex = k + 1;
        break;
      }
    }

    console.log("------------start of real data-----------------------------");

    //Clear LED Screen
    const reponse1 = await post_www_url_encoded({
      "command": "@"
    });


    for (let i = startDataIndex; i < pbmfile.size; i++) {
      for (let j = 7; j >= 0; j--) {
        let val = rawbuffer[i] & (1 << j);
        if (val) {
          console.log("1 at (", row, ",", column, ")");
          //Set pixel (row,column)
          let response2 = await post_www_url_encoded({
            "command": "P",
            "x": column,
            "y": row,
            "val": 1
          });

          //canvas->setPixel(row,column,1);
        }

        else {
          console.log("0 at (", row, ",", column, ")");
          //canvas->setPixel(row,column,0);
        }

        column = column + 1;
        if (column === width) {
          row = row + 1;
          column = 0;
        }


      }

    }
    //Updates LED with contents of canvas/in-memory buffer
    const reponse3 = await post_www_url_encoded({
      "command": "U"
    });
  });
  reader.readAsArrayBuffer(pbmfile);
}

export { post_www_url_encoded, handleFiles };