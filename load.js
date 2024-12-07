(() => {

    async function DOMLoaded()
    {
        const response = await fetch('data.txt')
        if (!response.ok)
            return

        const body = await response.text()

        const element = document.querySelector('main pre')
        element.innerText = body
    }

    document.addEventListener('DOMContentLoaded', DOMLoaded)
})()