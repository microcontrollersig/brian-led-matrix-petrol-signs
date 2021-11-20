<script>
    import { post_www_url_encoded } from "./imageupload";

    let categories = [
        {
            id: "country",
            name: "Country",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/countries-limited.json",
        },
        {
            id: "fruit",
            name: "Fruit",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/fruits-limited.json",
        },
        {
            id: "vegetable",
            name: "Vegetable",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/vegetables-limited.json",
        },
        {
            id: "animal",
            name: "Animal",
            url: "https://cdn.jsdelivr.net/gh/raspberrypisig/corpora/custom/animals-limited.json",
        },
    ];

    let answer;
    let revealedLetters = new Set();
    let categorySelection = "";
    let availableLetters = [
        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N",
        "O",
        "P",
        "Q",
        "R",
        "S",
        "T",
        "U",
        "V",
        "W",
        "X",
        "Y",
        "Z",
    ];

    function selectCategory(id) {
        const selectedCategories = categories.filter(
            (category) => category.id === id
        );
        const selectedCategory = selectedCategories[0];
        categorySelection = selectedCategory.name;
        const selectedCategoryName = selectedCategory.name.toLocaleUpperCase();
        const selectedCategoryURL = selectedCategory.url;

        // converted github link to jsdelivr CDN
        fetch(selectedCategoryURL)
            .then((response) => response.json())
            .then((data) => {
                console.log(data);
                const item = data[Math.floor(Math.random() * data.length)];
                const itemCapitalized = item.toUpperCase();

                const categoryNameSize = selectedCategoryName.length;
                const itemSize = itemCapitalized.length;
                answer = itemCapitalized;
                console.log("category", selectedCategoryName);
                console.log("category name size:", categoryNameSize);
                console.log("random item:", itemCapitalized);
                console.log("random item size:", itemSize);
                post_www_url_encoded({
                    command: "@",
                });

                const spaces = Array(itemSize).fill(" ");
                const underscores = Array(itemSize).fill("_");

                var words = underscores.reduce(function (arr, v, i) {
                    return arr.concat([v, " "]);
                }, []);

                console.log(words);

                post_www_url_encoded({
                    command: "T",
                    x1: 0,
                    y1: 16,
                    text1: selectedCategoryName,
                    x2: 0,
                    y2: 24,
                    text: words.join(""),
                    fontIndex: 1,
                });
            });
    }
</script>

<main>
    <h1>Hangman</h1>
    <section>
        <h2>Select category</h2>
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
    <section>
        <h2>Category</h2>
        <p>{categorySelection}</p>
    </section>
    <section>
        <h2>Select Letter</h2>
        {#each availableLetters as letter}
            <button class="letters">{letter}</button>
        {/each}
    </section>
</main>

<style lang="scss">
    .letters {
        margin-left: 30px;
    }
</style>
