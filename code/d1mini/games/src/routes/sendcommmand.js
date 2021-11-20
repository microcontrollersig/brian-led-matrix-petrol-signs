async function post_www_url_encoded(data) {
    const body = new URLSearchParams();
    for (let key in data) {
        body.append(key, data[key]);
    }
    return await fetch('/command', { method: "POST", body });
}

export { post_www_url_encoded };
