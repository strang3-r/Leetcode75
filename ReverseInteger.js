/**
 * @param {number} x
 * @return {number}
 */
const reverse = (x) => {
    if(x < 0){
        return -1*reverse(-x);
    }
    
    const solution = (x+"").split('').reverse().join('');

    return (solution > 2**31-1) ? 0 : solution;

};