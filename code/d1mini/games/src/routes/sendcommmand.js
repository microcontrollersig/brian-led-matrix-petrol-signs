async function post_www_url_encoded(data) {
    const body = new URLSearchParams();
    for (let key in data) {
        body.append(key, data[key]);
    }
    //console.log(body);
    return await fetch('/command', { method: "POST", body });
}

function send_multiple(dataCollection) {
    dataCollection.forEach(element => {
        post_www_url_encoded(element);
    });

}

export { post_www_url_encoded, send_multiple };
