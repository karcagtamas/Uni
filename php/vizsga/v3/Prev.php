<?php


class Prev
{
    private Subject $subject;

    public function __construct(Subject $subject) {
        $this->subject = $subject;
    }

    public function getSubject() :Subject {
        return $this->subject;
    }
}