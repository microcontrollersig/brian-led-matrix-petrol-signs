<script>
    let categories = [
        {
            id: "countries",
            name: "Countries",
            url: "https://cdn.jsdelivr.net/gh/samayo/country-json/src/country-by-name.json",
        },
        {
            id: "fruits",
            name: "Fruits",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/fruits.json",
        },
        {
            id: "vegetables",
            name: "Vegetables",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/vegetables.json",
        },
        {
            id: "animals",
            name: "Animals",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/animals.json",
        },
    ];

    function selectCategory(id) {
        const selectedCategories = categories.filter(
            (category) => category.id === id
        );
        const selectedCategory = selectedCategories[0];
        const selectedCategoryURL = selectedCategory.url;

        // converted github link to jsdelivr CDN
        fetch(selectedCategoryURL)
            .then((response) => response.json())
            .then((data) => {
                console.log(data);
            });
    }
</script>

<main>
    <h1>Hangman</h1>
    <section>
        <h2>Categories</h2>
        <ul>
            {#each categories as category}
                <li>
                    <a
                        class="categories"
                        id={category.id}
                        on:click={() => selectCategory(category.id)}
                        >{category.name}</a
                    >
                </li>
            {/each}
        </ul>
    </section>
</main>

<style lang="scss">
</style>
