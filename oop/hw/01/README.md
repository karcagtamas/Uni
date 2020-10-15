Készítsen programot, ami a mellékelt CSV fájlból beolvassa a harcoló hősök listáját! Vizsgálja meg a CSV fájl tartalmát: a tárolt adatok (és a feladatkiírás) alapján készítsen egy osztályt! Nézzen utána az esetleg még nem tanult, ismeretlen dolgoknak!

A program egy játékot szimuláljon:

1.       Listázza ki, a hősöket és tulajdonságaikat.

2.       A felhasználó válasszon ki az elején két hőst.

3.       A szimuláció körökre osztott. Minden körben sebezzék meg egymást a hősök, az alábbi összefüggés alapján: precision * uniform_random(min_DPS, max_DPS)

4.       Minden játékoshoz tartozik egy speciális képesség. Minden hős egy körben 5%-os valószínűséggel használja képességét. A képességhez tartozik egy speciális sebzés, ami teljes értékben sebzi az ellenfelet.

5.       A szimuláció mindaddig folytatódjon, ameddig az egyik hős életereje nem lesz 0 egy kör végén.