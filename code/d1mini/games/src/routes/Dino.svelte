<script>
    import { onMount } from "svelte";
    import { post_www_url_encoded, send_multiple } from "./sendcommmand.js";

    function arrowDownPressed() {
        //
    }

    function arrowUpPressed() {
        //
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
                typeIndex: 1,
                objectindex: 0,
                x: 80,
                y: 16,
            },
            {
                dinocommand: "z",
                subcommand: "d",
                typeindex: 2,
                objectindex: 0,
                x: 6,
                y: 5,
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
