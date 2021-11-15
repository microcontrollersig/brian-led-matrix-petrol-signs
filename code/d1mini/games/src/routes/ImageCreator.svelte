<script>


import { onMount } from "svelte";


const LEDPanelCount = 3072;
let LEDPanelData = new Array(LEDPanelCount).fill(0);  
const LEDCount = 256;
const hiddencheckboxclassName = Array.from(Array(LEDCount).keys(), x => "c" + x);
const hiddenlabelclassName =    Array.from(Array(LEDCount).keys(), x => [ "s" + x,  "c" + x]);
let panel_x = 0;
let panel_y = 0;

function str2ab(str) {
  var buf = new ArrayBuffer(str.length); // 2 bytes for each char
  var bufView = new Uint8Array(buf);
  for (var i=0, strLen=str.length; i<strLen; i++) {
    bufView[i] = str.charCodeAt(i);
  }
  return buf;
}

function SaveFile() {
  const data = new Uint8Array(LEDPanelData);
  const headerstring = "P4\n96 32\n"
  //const header = new Uint8Array(9);
  
  const header = str2ab(headerstring);
  const headerView = new Uint8Array(header);
  const buf = new Uint8Array(data.length + headerView.length).fill(0);
  buf.set(headerView, 0);
  buf.set(data, headerView.length);
  console.log(buf);
  if (window.navigator.msSaveOrOpenBlob) {
   window.navigator.msSaveOrOpenBlob(buf.buffer, "blob.pbm");
  }
  else {
   const a = document.createElement("a");
   document.body.appendChild(a);
   const url = (window.URL ? URL : webkitURL).createObjectURL(new Blob([buf]), {type: "data:application/octet-stream;base64,"});
   a.href = url;
   const date = new Date(Date.now());
   const options = {weekday: 'short', month: 'short', day: 'numeric', hour: 'numeric', minute: 'numeric', seconds: 'numeric' };
   a.download = "brians-petrol-signs-"  + date.toLocaleString('en-AU', options).replaceAll(",", "-").replace(/\s/g, "")  + ".pbm";
   a.click();
   setTimeout(() => {
     window.URL.revokeObjectURL(url);
     document.body.removeChild(a);
   }, 0);
  }
} 

function post_www_url_encoded(data) {
    const body = new URLSearchParams();
    for (let key in data) {
      body.append(key, data[key]);
    }
    fetch('/command', {method: "POST", body}); 
}

function drawPixel(x, y, val) {
   const data = {
     "command": "Y",
     "x": x,
     "y": y,
     "val": val
   };
   post_www_url_encoded(data); 
}

onMount( () => {
  document.getElementById("saveButton").addEventListener("click", (event) => {
    //console.log(LEDPanelData);
    SaveFile();
  });

  document.querySelectorAll('input[type=checkbox]').forEach( (checkbox) => {
    checkbox.addEventListener("click", (event) =>  {      
      const ledindex = event.target.id.substring(1);
      if (event.target.checked === true)
        LEDPanelData[ledindex] = 1;
      else
        LEDPanelData[ledindex] = 0;

      const x = ledindex % 16 + 16*panel_x;
      const y = Math.floor(ledindex / 16) + 16*panel_y;
      console.log("x:", x, " y:", y, "val:", LEDPanelData[ledindex]);
      drawPixel(x, y, LEDPanelData[ledindex]);
  
    });
  });
  

} );

</script>

<main>
<section id="menu">
  <ul>
    <li><button id="saveButton">SAVE</button></li>
  </ul>
</section> 

    {#each hiddencheckboxclassName as checkboxclassname }
        <input type="checkbox" id="{checkboxclassname}" name="{checkboxclassname}" />    
    {/each}    
    

    
    <section id="guts">

    <div id="board" class="grid">
        {#each hiddenlabelclassName as label}
        <label for="{label[1]}" id="{label[0]}" class="grid__item"></label>
        {/each}
        
    </div>
    <div id="panelselection">PANEL SELECTION</div>
  </section>    

</main>

<style lang="scss">

#guts {
  display:grid;
  grid-template-columns: repeat(2, 1fr);
}

ul button {
  margin:0;
}

ul {
  padding: 0;
  margin-bottom:5px;
}

.grid {
    display: -ms-grid;
    -ms-grid-columns: repeat(16, 1fr);
    -ms-grid-rows: auto;
    display: grid;
    grid-template-columns: repeat(16, 1fr);
    grid-template-rows: auto;
    
  }

.buttons {
  max-width: 800px;
  margin: 30px auto;
  box-sizing: border-box;

  button {
    width: 6rem;
  }
}
  
.grid__item::before {
    content: "";
    display: block;
    padding-top: 100%;
  }
  
  body {
    padding: 0;
    margin: 0;
    background-color: #212121;
  }
   .grid {
    max-width: 600px;
    /*margin: 30px auto;*/
    box-sizing: border-box;
    border: 10px solid #2a351f;
  }
   .grid__item {
    /*background-color: #eeedd3;*/
    background: #c0c0c0;
    border: 2px outset #ececec;
    transition: all 400ms linear;
  }

  $columns: 255;

  @for $i from 0 through $columns {
    #c#{$i}:checked ~ section .grid #s#{$i} {        
        background-color: green;    
        margin: 0px;  
        transform: scale(1.0);      
    }
  }

  /*

  #c1:checked ~ .grid #s1 {
    background-color: green;    
    margin: 0px;  
    transform: scale(1.0);
  
  }
  
  #c2:checked ~ .grid #s2 {
    background-color: green;
    margin: 0px;
    transform: scale(1.0);
  }
  */

  
  input {
    visibility: hidden;
    position: absolute;
    top: -99px;
    left: -99px;
  }
  
  .selected {
    color: red;
  }
  
  
</style>