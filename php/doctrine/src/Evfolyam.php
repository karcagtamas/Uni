<?php
    declare(strict_types = 1);

    use Doctrine\ORM\EntityManager;

    class Evfolyam {
        private $em;

        public function __construct(EntityManager $em) {
            $this->em = $em;
        }

        public function feldolgozas() {
            if (isset($_POST["mod"]) && in_array($_POST["mod"], ['beszur', 'csere', 'torles'])) {
                try {
                    switch($_POST["mod"]) {
                        case 'beszur':
                            $hg = new Hallgato($_POST["neptun"], $_POST["nev"], new DateTime($_POST["szuldatum"]));

                            $this->em->persist($hg);
                            break;
                        case 'csere':
                            $hg = $this->em->find('Hallgato', $_POST["neptun"]);
                            if ($hg == null) {
                                throw new Exception();
                            }
                            $hg->setNev($_POST["nev"]);
                            $hg->setSzuldatum(new DateTime($_POST["szuldatum"]));
                            break;
                        case 'torles':
                            $hg = $this->em->find('Hallgato', $_POST["neptun"]);
                            if ($hg == null) {
                                throw new Exception();
                            }
                            $this->em->remove($hg);
                            beark;
                    }
                    $this->em->flush();
                } catch (Exception $e) {
                    echo "<p style=\"color: red\">{$_POST["neptun"]} ".
                        "kódú hallgató nem létezik. </p>\n";
                }
            }
        }

        public function lista() {
            echo "<h1>A hallgatók listája:</h1>\n";
            $hallgatoRepository = $this->em->getRepository('Hallgato');
            $hallgatok = $hallgatoRepository->findAll();

            foreach ($hallgatok as $hg) {
                echo "<p>{$hg}</p>\n";
            }
        }
    }