var linhas, colunas, bombas, matriz, tabela;

function gerarMatriz(l, c) {
    matriz = [];
    for (var i = 0; i < l; i++) {
        matriz[i] = new Array(c).fill(0);
    }
    console.log(matriz);
}

function gerarTabela(l, c) {
    gerarMatriz(l, c);
    var str = "";
    for (var i = 0; i < l; i++) {
        str += "<tr>";
        for (var j = 0; j < c; j++) {
            str += "<td class='blocked'></td>";
        }
        str += "</tr>";
    }
    tabela.innerHTML = str;
}

function mostrarMatriz() {
    for (var i = 0; i < linhas; i++) {
        for (var j = 0; j < colunas; j++) {
            if (matriz[i][j] === -1) {
                tabela.rows[i].cells[j].innerHTML = "&#128163;";
            } else {
                tabela.rows[i].cells[j].innerHTML = matriz[i][j];
            }
        }
    }
}

function gerarBombas() {
    for (var i = 0; i < bombas;) {
        var linha = Math.floor((Math.random() * linhas));
        var coluna = Math.floor((Math.random() * colunas));
        if (matriz[linha][coluna] === 0) {
            matriz[linha][coluna] = -1;
            i++;
        }
    }
}

function gerarNumero(l, c) {
    var count = 0;
    for (var i = l - 1; i <= l + 1; i++) {
        for (var j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < linhas && j >= 0 && j < colunas) {
                if (matriz[i][j] === -1) {
                    count++;
                }
            }
        }
    }
    matriz[l][c] = count;
}

function gerarNumeros() {
    for (var i = 0; i < linhas; i++) {
        for (var j = 0; j < colunas; j++) {
            if (matriz[i][j] !== -1) {
                gerarNumero(i, j);
            }
        }
    }
}

function bandeira(event) {
    var cell = event.target;
    var linha = cell.parentNode.rowIndex;
    var coluna = cell.cellIndex;
    if (cell.className === "blocked") {
        cell.className = "flag";
        cell.innerHTML = "&#128681;";
    } else if (cell.className === "flag") {
        cell.className = "blocked";
        cell.innerHTML = "";
    }
    return false;
}

function init() {
    tabela = document.getElementById("tabela");
    tabela.onclick = verificar;
    tabela.oncontextmenu = bandeira;

    gerarTabela(linhas, colunas);
    gerarBombas();
    gerarNumeros();
}

function limparCelulas(l, c) {
    for (var i = l - 1; i <= l + 1; i++) {
        for (var j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < linhas && j >= 0 && j < colunas) {
                var cell = tabela.rows[i].cells[j];
                if (cell.className !== "blank") {
                    switch (matriz[i][j]) {
                        case -1:
                            break;
                        case 0:
                            cell.innerHTML = "";
                            cell.className = "blank";
                            limparCelulas(i, j);
                            break;
                        default:
                            cell.innerHTML = matriz[i][j];
                            cell.className = "n" + matriz[i][j];
                    }
                }
            }
        }
    }
}

function mostrarBombas() {
    for (var i = 0; i < linhas; i++) {
        for (var j = 0; j < colunas; j++) {
            if (matriz[i][j] === -1) {
                var cell = tabela.rows[i].cells[j];
                cell.innerHTML = "&#128163;";
                cell.className = "blank";
            }
        }
    }
}

function verificar(event) {
    var cell = event.target;
    if (cell.className !== "flag") {
        var linha = cell.parentNode.rowIndex;
        var coluna = cell.cellIndex;
        switch (matriz[linha][coluna]) {
            case -1:
                mostrarBombas();
                cell.style.backgroundColor = "red";
                tabela.onclick = undefined;
                tabela.oncontextmenu = undefined;
                mostrarResultado("derrota");
                break;
            case 0:
                limparCelulas(linha, coluna);
                break;
            default:
                cell.innerHTML = matriz[linha][coluna];
                cell.className = "n" + matriz[linha][coluna];
        }
        fimDeJogo();
    }
}

function fimDeJogo() {
    var cells = document.querySelectorAll(".blocked, .flag");
    if (cells.length === bombas) {
        mostrarBombas();
        tabela.onclick = undefined;
        tabela.oncontextmenu = undefined;
        mostrarResultado("vitoria");
    }
}

function setDificuldade(nLinhas, nColunas, nBombas) {
    linhas = nLinhas;
    colunas = nColunas;
    bombas = nBombas;
    init();
}

function registerEvents() {
    document.querySelector(".facil").addEventListener("click", function () {
        visibilidade();
        setDificuldade(9, 9, 10);
    });

    document.querySelector(".medio").addEventListener("click", function () {
        visibilidade();
        setDificuldade(12, 12, 40);
    });

    document.querySelector(".dificil").addEventListener("click", function () {
        visibilidade();
        setDificuldade(16, 30, 99);
    });

    init();
}
function visibilidade() {
    var campominado = document.querySelector(".campominado");
    var tela1 = document.querySelector(".tela1");
    campominado.style.display = "flex";
    tela1.style.display = "none";
}
function mostrarResultado(resultado) {
    var finaldojogo = document.querySelector(".fimdejogo");
    var mensagem = document.querySelector(".status");
    var reiniciarbtn = document.querySelector(".restart");

    if (resultado === "vitoria") {
        mensagem.textContent = "venceu";
    } else if (resultado === "derrota") {
        mensagem.textContent = "perdeu";
    }

    finaldojogo.style.display = "flex";

    reiniciarbtn.addEventListener("click", function () {
        location.reload();
    });
}


onload = registerEvents;
