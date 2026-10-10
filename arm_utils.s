				AREA    |.text|, CODE, READONLY
                EXPORT  get_cpsr

get_cpsr        PROC
                MRS     R0, CPSR            ; Copy CPSR into R0
                BX      LR                  ; Return to caller
                ENDP

                END