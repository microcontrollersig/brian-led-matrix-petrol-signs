<script>
  import { onMount } from "svelte";
  import { handleFiles } from "./imageupload.js";

  onMount(() => {
    const inputElement = document.getElementById("input");
    inputElement.addEventListener("change", handleFiles, false);
  });
</script>

<main>
  <section>
    <h1>Image Upload</h1>
    <p>Please upload a binary PBM file</p>
    <div>
      <input type="file" id="input" />
    </div>
  </section>
</main>

<style>
</style>
