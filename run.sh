#!/usr/bin/sbcl --script

(require :asdf)
(import :asdf)
(asdf:operate 'asdf:load-op :lccyao2)
(lccyao-main:pcf-simulate (lccyao-main:load-pcf-ops (second sb-ext:*posix-argv*) ) (third sb-ext:*posix-argv*))
