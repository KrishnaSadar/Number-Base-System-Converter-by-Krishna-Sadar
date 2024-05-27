// script.js

function toInteger(c) {
    if (c >= '0' && c <= '9') return c.charCodeAt(0) - '0'.charCodeAt(0);
    if (c >= 'A' && c <= 'Z') return c.charCodeAt(0) - 'A'.charCodeAt(0) + 10;
    if (c >= 'a' && c <= 'z') return c.charCodeAt(0) - 'a'.charCodeAt(0) + 10;
    return -1;
}

function toCharacter(n) {
    if (n >= 0 && n <= 9) return String.fromCharCode(n + '0'.charCodeAt(0));
    if (n >= 10 && n < 36) return String.fromCharCode(n - 10 + 'A'.charCodeAt(0));
    return '!';
}

function valid(number, base) {
    for (let i = 0; i < number.length; i++) {
        if (number[i] === '.') continue;
        if (toInteger(number[i]) >= base || toInteger(number[i]) === -1) {
            return false;
        }
    }
    return true;
}

function cTod(number, base) {
    let result = 0;
    let length = number.length;
    for (let i = 0; i < length; i++) {
        if (number[i] === '.') break;
        result += toInteger(number[i]) * Math.pow(base, length - i - 1);
    }
    return result;
}

function cFromd(n, base) {
    let temp = [];
    if (n === 0) return '0';
    while (n > 0) {
        temp.push(toCharacter(n % base));
        n = Math.floor(n / base);
    }
    return temp.reverse().join('');
}

function validFractional(number, base) {
    let pointSeen = false;
    for (let i = 0; i < number.length; i++) {
        if (number[i] === '.') {
            if (pointSeen) return false;
            pointSeen = true;
            continue;
        }
        if (toInteger(number[i]) >= base || toInteger(number[i]) === -1) {
            return false;
        }
    }
    return true;
}

function convertFractionalPart(number, inputBase, outputBase) {
    let fractionalValue = 0.0;
    let pointIndex = number.indexOf('.');
    for (let i = pointIndex + 1; i < number.length; i++) {
        fractionalValue += toInteger(number[i]) * Math.pow(inputBase, -(i - pointIndex));
    }

    let result = '';
    let tempIndex = 0;
    while (fractionalValue > 0 && tempIndex < 10) {
        fractionalValue *= outputBase;
        let fractionalDigit = Math.floor(fractionalValue);
        result += toCharacter(fractionalDigit);
        fractionalValue -= fractionalDigit;
        tempIndex++;
    }
    return result;
}

document.getElementById('inputBase').addEventListener('change', function () {
    if (this.value === 'other') {
        document.getElementById('customInputBase').style.display = 'inline';
    } else {
        document.getElementById('customInputBase').style.display = 'none';
    }
});

function convertNumber() {
    let inputBase = document.getElementById('inputBase').value;
    if (inputBase === 'other') {
        inputBase = parseInt(document.getElementById('customInputBase').value);
    } else {
        inputBase = parseInt(inputBase);
    }
    let numberInput = document.getElementById('numberInput').value;
    let outputBase = parseInt(document.getElementById('outputBase').value);

    if (!validFractional(numberInput, inputBase)) {
        document.getElementById('result').innerText = `Invalid Number for the base ${inputBase}. Please try again.`;
        showPopup();
        return;
    }

    let result;
    if (numberInput.includes('.')) {
        let integerPart = numberInput.split('.')[0];
        let fractionalPart = '.' + numberInput.split('.')[1];
        let temp = cTod(integerPart, inputBase);
        let convertedIntegerPart = cFromd(temp, outputBase);
        let convertedFractionalPart = convertFractionalPart(fractionalPart, inputBase, outputBase);
        result = `${convertedIntegerPart}.${convertedFractionalPart}`;
    } else {
        let temp = cTod(numberInput, inputBase);
        result = cFromd(temp, outputBase);
    }

    document.getElementById('result').innerText = `The Number in base ${outputBase} is: ${result}`;
    showPopup();
}

function showPopup() {
    document.getElementById('popup').style.display = 'block';
}

function closePopup() {
    document.getElementById('popup').style.display = 'none';
}
