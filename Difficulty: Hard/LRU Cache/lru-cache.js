//{ Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let capacity = parseInt(readLine());
        let cache = new LRUCache(capacity);
        let queries = parseInt(readLine());
        let input_ar1 = readLine().split(' ');
        let index = 0;
        let s = '';
        while(queries--){
            let q = input_ar1[index++];
            if(q === "SET"){
                let key = parseInt(input_ar1[index++]);
                let value = parseInt(input_ar1[index++]);
                cache.set(key, value);
            }
            else{
                let key = parseInt(input_ar1[index++]);
                s += cache.get(key) + " ";
            }
        }
        console.log(s);
        
    }
}
// } Driver Code Ends


class LRUCache {
    constructor(cap) {
        this.capacity = cap;
        this.cache = new Map();
    }

    get(key) {
        if (!this.cache.has(key)) return -1;
        const value = this.cache.get(key);
        this.cache.delete(key);
        this.cache.set(key, value);
        return value;
    }

    set(key, value) {
        if (this.cache.has(key)) this.cache.delete(key);
        this.cache.set(key, value);
        if (this.cache.size > this.capacity) {
            const leastUsedKey = this.cache.keys().next().value;
            this.cache.delete(leastUsedKey);
        }
    }
}


