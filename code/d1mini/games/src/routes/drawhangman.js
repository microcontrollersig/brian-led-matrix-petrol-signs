

const hangman =
    [

        [
            new Map([
                ["command", "Q"],
                ["x", 10],
                ["y", 0],
                ["width", 2],
                ["height", 13],
                ["color", 1]
            ]
            ),
            new Map([
                ["command", "Q"],
                ["x", 10],
                ["y", 0],
                ["width", 22],
                ["height", 2],
                ["color", 1]
            ]
            ),
            new Map([
                ["command", "Q"],
                ["x", 5],
                ["y", 13],
                ["width", 12],
                ["height", 2],
                ["color", 1]
            ]
            ),
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 2],
                ["x2", 31],
                ["y2", 4],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "N"],
                ["centerx", 31],
                ["centery", 6],
                ["radius", 2],
                ["bordercolor", 1],
                ["fillcolor", 0]
            ]
            )
        ],
        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 8],
                ["x2", 31],
                ["y2", 9],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 9],
                ["x2", 25],
                ["y2", 6],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 9],
                ["x2", 37],
                ["y2", 6],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 9],
                ["x2", 31],
                ["y2", 10],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 10],
                ["x2", 25],
                ["y2", 14],
                ["color", 1]
            ]
            )
        ],

        [
            new Map([
                ["command", "L"],
                ["x1", 31],
                ["y1", 10],
                ["x2", 37],
                ["y2", 14],
                ["color", 1]
            ]
            )
        ]


    ];

function drawHangmanPart(index) {
    let drawingCommands = [];

    for (const elem of hangman[index]) {
        const body = new URLSearchParams();
        elem.forEach(function (v, k) {
            body.append(k, v);
        });

        drawingCommands.push(fetch('/command', { method: "POST", body }));
    }

    Promise.all(drawingCommands);
}

export { drawHangmanPart };