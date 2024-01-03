document.body.style.border = "5px solid red";

let textInfo = null

async function lifeCheck() {
	const res = await fetch("http://localhost:8080/ping")
	return res.status === 0
}

async function fetchCode() {
	try {
		const res = await fetch("http://localhost:8080/code")
		if (res.status !== 200) {
			log("Fetching code failed")
			return null
		}
		const code = await res.text();
		return code;
	} catch (e) {
		log("Fetching code failed")
		return null
	}
	
}

const updateCode = async (e) => {

	debug("Fetching code")
	
	const code = await fetchCode()

	if (!code) {
		textInfo.textContent = `[CG-Sync] Update failed`
		return
	}

	textInfo.textContent = `[CG-Sync] Last update : ${new Date().toLocaleTimeString()}`

	let data = {status: "updateCode", code}

	data = cloneInto(data, window);

	const ev = new CustomEvent('ExternalEditorToIDE', { detail: data });
	window.document.dispatchEvent(ev);

}

window.document.addEventListener('focus', updateCode);

log("Script started")
// We wait before injecting cg-sync state elements
setTimeout(async () => {
	log("Loading elements in page")

	textInfo = document.createElement("button") 
	textInfo.textContent = `[CG-Sync] Waiting for first sync...`
	textInfo.style = "color: rgb(0, 255, 255)"
	textInfo.onclick = () => updateCode()
	
	const actionRowDocument = window.document.getElementsByClassName("code-header")
	actionRowDocument[0].children[0].after(textInfo)
	updateCode()
}, 3000)
