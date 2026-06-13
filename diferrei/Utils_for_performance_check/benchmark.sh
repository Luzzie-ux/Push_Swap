#!/bin/bash

# Configurações do teste
NUM_TESTS=10
SIZE_100=100
SIZE_500=500

run_bench() {
    local size=$1
    local total_ops=0
    local max_ops=0
    local min_ops=999999

    echo "A testar com $size números ($NUM_TESTS iterações)..."
    for i in $(seq 1 $NUM_TESTS); do
        ARG=$(shuf -i 0-9999 -n $size | tr '\n' ' ')
        # Executa o push_swap e guarda as operações
OUTPUT=$(./push_swap $ARG)

# Valida com o teu checker (substitui pelo nome correto do teu checker)
CHECK_RESULT=$(echo "$OUTPUT" | ./checker_linux $ARG)

if [ "$CHECK_RESULT" = "KO" ]; then
    echo "❌ BUG ENCONTRADO!"
    echo "Input que falhou:"
    echo "$ARG"
    echo "---------------------------------------"
    exit 1
fi
        ./push_swap $ARG | ./checker_linux $ARG
        OPS=$(./push_swap $ARG | wc -l)
        
        total_ops=$((total_ops + OPS))
        [ $OPS -gt $max_ops ] && max_ops=$OPS
        [ $OPS -lt $min_ops ] && min_ops=$OPS
    done

    echo "-> Média: $((total_ops / NUM_TESTS)) operações"
    echo "-> Máximo: $max_ops operações"
    echo "-> Mínimo: $min_ops operações"
    echo "---------------------------------------"
}

# Executa para 100 e 500 números
run_bench $SIZE_100
run_bench $SIZE_500
