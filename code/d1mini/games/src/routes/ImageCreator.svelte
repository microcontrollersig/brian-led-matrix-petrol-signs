<script>
const LEDCount = 256;
const hiddencheckboxclassName = Array.from(Array(LEDCount).keys(), x => "c" + x);
const hiddenlabelclassName =    Array.from(Array(LEDCount).keys(), x => [ "s" + x,  "c" + x]);
</script>

<main>


    {#each hiddencheckboxclassName as checkboxclassname }
        <input type="checkbox" id="{checkboxclassname}" name="{checkboxclassname}" />    
    {/each}    
    

    
    <div id="board" class="grid">
        {#each hiddenlabelclassName as label}
        <label for="{label[1]}" id="{label[0]}" class="grid__item"></label>
        {/each}
        
    </div>

</main>

<style lang="scss">
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
    margin: 30px auto;
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
    #c#{$i}:checked ~ .grid #s#{$i} {        
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