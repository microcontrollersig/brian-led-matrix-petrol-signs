<script>
    import { onMount } from "svelte";
    import { post_www_url_encoded } from "./sendcommmand.js";

    let isInitializing = true;
    let timeRemaining = 60;

    function updateTime() {
        setInterval(() => {
            const currentDate = new Date();
            const time =
                currentDate.getHours() + ":" + currentDate.getMinutes();
            post_www_url_encoded({
                command: "V",
                time: time,
            });
        }, 60000);
    }

    onMount(() => {
        const currentDate = new Date();
        const seconds = currentDate.getSeconds();
        timeRemaining = 60 - seconds;

        setTimeout(() => {
            isInitializing = false;
            updateTime();
        }, timeRemaining * 1000);
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
