<script>
    import { onMount } from "svelte";
    import { post_www_url_encoded } from "./sendcommmand.js";

    onMount(() => {
        post_www_url_encoded({
            command: "^",
            timeout: "3000",
        });
    });
</script>

<main>
    <h1>Random Number Generator (between 1 and 100)</h1>
</main>

<style>
</style>
