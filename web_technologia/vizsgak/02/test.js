function test() {
    'use strict'

    function setUp() {
        console.log("start");
    }

    function testGetMark() {
        jsUnity.assertions.assertEqual(getMark(1), 1);
        jsUnity.assertions.assertEqual(getMark(12), 1);
        jsUnity.assertions.assertEqual(getMark(26), 2);
        /*jsUnity.assertions.assertEqual(getMark(29), 2);
        jsUnity.assertions.assertEqual(getMark(31), 3);
        jsUnity.assertions.assertEqual(getMark(44), 4);
        jsUnity.assertions.assertEqual(getMark(50), 5);*/
    }

    function tearDown() {
        console.log("end");
    }
}

jsUnity.log = function (msg) {
    console.log(msg);
}

jsUnity.run(test);