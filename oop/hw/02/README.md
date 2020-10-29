Valósítsa meg az életjátékot (Conway https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) C++ program segítségével! Ez egy klasszikus probléma a programozási feladatok esetében. Hozzon létre egy a program kezdetekor állítható rácsot, amiben sejtek tárolhatók. A sejtek működését azok szomszédjainak száma határozza meg:

-          Minden élő sejt, aminek egy vagy annál kevesebb sejtszomszédja van, elpusztul a következő ciklusban, vagyis szabaddá válik a cella.

-          Minden élő sejt, aminek kettő vagy három szomszédja van, túléli a következő ciklust.

-          Minden élő sejt, aminek háromnál több szomszédja van, elpusztul.

-          Minden cella, ahol pontosan három szomszédos cellában található sejt, új élő sejt keletkezik.

A cellákat véletlenszerűen töltse fel a program indításakor. A ciklus előrehaladása automatikus legyen, ne legyen szükség a felhasználó beavatkozására (időzítés). Ha ez elkészült, a következőket valósítsa meg:

-         Állítson be a cellának programozott halált. Vagyis egy előre definiált ciklusszám után minden sejt pusztuljon el.

-     Szimulálja a rákos sejteket: legyen sejteknek egy csoportja, amire nem érvényes a programozott halál. Mit tapasztal?   