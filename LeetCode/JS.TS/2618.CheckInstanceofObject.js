/**
 * param {*} obj
 * param {*} classFunction
 * return {boolean}
 */
var checkIfInstanceOf = function (obj, classFunction) {
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false
    }

    const objPrototype = Object.getPrototypeOf(obj)
    console.log(objPrototype)

    if (objPrototype === classFunction.prototype) {
        return true
    }

    return checkIfInstanceOf(objPrototype, classFunction)
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */