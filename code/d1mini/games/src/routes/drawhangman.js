

const hangman =
    [

        [
            new Map([
                ["command", "Q"],
                ["x", 10],
                ["y", 1],
                ["width", 2],
                ["height", 12],
                ["color", 1]
            ]
            )
        ]


    ];

function drawHangmanPart(index) {
    let drawingCommands = [];

    for (const elem of hangman[index]) {
        //const searchParams = new URLSearchParams(elem);
        //const drawingCommand = searchParams.toString();
        //console.log(drawingCommand);
        //console.log(searchParams);
        const body = new URLSearchParams();
        elem.forEach(function (v, k) {
            body.append(k, v);
        });

        drawingCommands.push(fetch('/command', { method: "POST", body }));
    }

    Promise.all(drawingCommands);
}

export { drawHangmanPart };