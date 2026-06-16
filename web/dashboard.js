function loadData()
{
    fetch("http://localhost:8080")
        .then(res => res.text())
        .then(data =>
        {
            document.getElementById("output").innerText = data;
        });
}