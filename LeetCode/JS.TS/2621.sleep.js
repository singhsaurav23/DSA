/**
 * param {number} millis
 * return {Promise}
 */
//promise needs to get resolved or rejected otherwise it will get hang in the execution in asynchronous
async function sleep(millis) {
    await new Promise((res) => {
        setTimeout(res, millis);
    })
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */