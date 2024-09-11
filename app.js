// Function to validate MAC address and redirect to result page
function validateForm(e) {
    e.preventDefault();
    const macInput = document.getElementById("macInput").value;
    const errorMsg = document.getElementById("errorMsg");

    if (validMAC(macInput)) {
        localStorage.setItem('mac', macInput); // Store MAC in localStorage
        window.location.href = 'result.html';  // Redirect to result page
    } else {
        errorMsg.style.display = "block";
    }
}

// Function to check if MAC address is valid
function validMAC(mac) {
    const macRegex = /^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$/;
    return macRegex.test(mac);
}

// Function to display result on result.html
window.onload = function () {
    const mac = localStorage.getItem('mac');
    if (mac) {
        const binaryMac = macToBinary(mac);
        const type = getMacType(mac);
        const resultContent = `
            <h2 class="mb-4 text-center">MAC Address Detail</h2>
            <p><strong>MAC Address (Hex):</strong> ${mac}</p>
            <p class = "binary"><strong>MAC Address (Binary):</strong> ${binaryMac}</p>
            <p><strong>Address Type:</strong> ${type}</p>
            <button class="btn btn-primary w-100" onclick="goBack()">Go Back</button>
        `;
        document.getElementById("resultContent").innerHTML = resultContent;
    }
};

// Function to convert MAC to binary
function macToBinary(mac) {
    return mac.split(':').map(hexToBinary).join(':');
}

// Function to convert hex to binary
function hexToBinary(hex) {
    return parseInt(hex, 16).toString(2).padStart(8, '0');
}

// Function to get the type of MAC address
function getMacType(mac) {
    const firstByteBinary = hexToBinary(mac.split(':')[0]);
    const lastBit = firstByteBinary[firstByteBinary.length - 1];
    if (mac === "ff:ff:ff:ff:ff:ff") return "Broadcast Type";
    return lastBit === '0' ? "Unicast Type" : "Multicast Type";
}

// Go back to the input page
function goBack() {
    localStorage.removeItem('mac');
    window.location.href = 'index.html';
}
