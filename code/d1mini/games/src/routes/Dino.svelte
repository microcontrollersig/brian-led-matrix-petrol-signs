<script>
  import { onMount } from "svelte";
  import { post_www_url_encoded, send_multiple } from "./sendcommmand.js";

  let x = 0;
  let isJumping = false;
  const y_initial = 5;
  const velocity_initial = 20;
  const g = 1;
  let y = y_initial;
  let velocity = velocity_initial;

  function arrowDownPressed() {
    //
  }

  function arrowUpPressed() {
    isJumping = true;
  }

  function spaceBarPressed() {
    post_www_url_encoded({
      command: "@",
    });

    const backgroundFull = [
      {
        dinocommand: "z",
        subcommand: "d",
        typeindex: 0,
        objectindex: 0,
        x: 0,
        y: 0,
      },
      {
        dinocommand: "z",
        subcommand: "d",
        typeindex: 0,
        objectindex: 1,
        x: 96,
        y: 0,
      },
      {
        dinocommand: "z",
        subcommand: "d",
        typeindex: 0,
        objectindex: 2,
        x: 192,
        y: 0,
      },
      {
        dinocommand: "z",
        subcommand: "d",
        typeindex: 0,
        objectindex: 0,
        x: 288,
        y: 0,
      },
      {
        dinocommand: "z",
        subcommand: "d",
        typeIndex: 1,
        objectindex: 0,
        x: 80,
        y: 16,
      },
      {
        dinocommand: "z",
        subcommand: "u",
        typeindex: -1,
        objectindex: -1,
        x: 0,
        y: 0,
      },
    ];

    send_multiple(backgroundFull);

    setInterval(() => {
      const data = [
        {
          command: "z",
          subcommand: "u",
          arg1: -1,
          arg2: -1,
          x: x,
          arg4: -1,
        },
        {
          dinocommand: "z",
          subcommand: "i",
          typeindex: 2,
          objectindex: 0,
          x: 5,
          y: y,
        },
      ];
      send_multiple(data);
      x = x + 1;
      if (x === 96 * 3) x = 0;

      if (isJumping) {
        y = y - 1;
        if (y === -1) {
          y = 5;
          isJumping = false;
        }
      }
    }, 200);
  }

  onMount(() => {
    document.addEventListener("keydown", function (event) {
      const keycode = event.code;
      if (keycode === "Space") {
        spaceBarPressed();
      } else if (keycode === "ArrowUp") {
        arrowUpPressed();
      } else if (keycode === "ArrowDown") {
        arrowDownPressed();
      }
    });
  });
</script>

<main>
  <h1>Dino</h1>
</main>

<style>
</style>
