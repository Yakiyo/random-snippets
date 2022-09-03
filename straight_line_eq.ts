/**
 * Simple function to generate equation
 * of a straight line passing thro the
 * provided two points. 
 */
interface Point {
    x: number,
    y: number 
}

function equation(a: Point, b: Point): string {
    const { x: x1, y: y1 } = a, { x: x2, y: y2 } = b;
    if (typeof x1 !== "number" || typeof x2 !== "number" || typeof y1 !== "number" || typeof y2 !== "number") throw new Error("Arguments a and b must be objects with values x and y which are of type number");
    const x = (() => {
        const cof = y1 - y2;
        if (cof > 0) return `${cof}x`;
        else if (cof < 0) return `- ${Math.abs(cof)}x`;
        else return '';
    })();
    const y = (() => {
        const cof = x2 - x1;
        if (cof > 0) return `+ ${cof}y`;
        else if (cof < 0) return `- ${Math.abs(cof)}y`;
        else return '';
    })();
    const c = (() => {
        const val = x1 * y2 - x2 * y1;
        if (val > 0) return `+ ${val}`;
        else if (val < 0) return `- ${Math.abs(val)}`;
        else return '';
    })();
    return `${x} ${y} ${c} = 0`;
}

console.log(equation({x: 4, y: 5}, {x: -2, y: -3})); // Returns "8x - 6y - 2 = 0"