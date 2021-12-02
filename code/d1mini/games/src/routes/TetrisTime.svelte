<script>
  import { onMount } from "svelte";
  import { post_www_url_encoded } from "./sendcommmand.js";

  let isInitializing = true;
  let timeRemaining = 60;
  let prevSeconds = 0;

  function updateTime() {
    const currentDate = new Date();
    let hours = currentDate.getHours().toString();
    let minutes = currentDate.getMinutes().toString();
    if (hours < 10) hours = "0" + hours;
    if (minutes < 10) minutes = "0" + minutes;
    const time = hours + ":" + minutes;
    post_www_url_encoded({
      command: "V",
      time: time,
    });
  }

  function setTime() {
    let currentDate = new Date();
    let currentSeconds = currentDate.getSeconds();
    if (prevSeconds === 59 && currentSeconds === 0) {
      prevSeconds = 0;
      updateTime();
    } else {
      prevSeconds = currentSeconds;
    }
    setTimeout(() => setTime(), 250);
  }

  function updateTimeRemaining() {
    const currentDate = new Date();
    const seconds = currentDate.getSeconds();
    if (seconds > 0) {
      timeRemaining = 60 - seconds;
      setTimeout(() => updateTimeRemaining(), 250);
    } else {
      isInitializing = false;
    }
  }

  onMount(() => {
    updateTimeRemaining();
    setTime();
  });
</script>

<main>
  <h1>Tetris Time Animation</h1>

  {#if isInitializing === true}
    Animation starts in {timeRemaining} seconds.
  {/if}
</main>

<style>
</style>
