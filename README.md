```markdown
# Simulador de Hidrômetro Analógico (v1)

Projeto da disciplina **Padrões de Projetos** – Engenharia de Computação.  
**Versão 1:** simula o funcionamento básico de um hidrômetro com **saída em terminal** e **registro em arquivo texto** (`saida.txt`).  
> Próximo passo (v2): **geração real de imagem (JPEG)** do mostrador do hidrômetro.

---

## ✨ O que esta versão faz

- **Simulação de volume** (m³ e mm) com:
  - vazão configurável (0–100 unidades/min),
  - sentido do fluxo (*Direto* conta, *Reverso* não conta),
  - simulação de “passagem de ar” (% de desconto).
- **Odômetro**: ao atingir o limite, volta para zero.
- **Saídas:**
  - **Terminal** (exibição textual da medição).
  - **Arquivo `saida.txt`** (estado atual do hidrômetro).
- Leitura de parâmetros via **`config.txt`**.

Exemplo de saída no terminal:
```

\[CONFIG] TFS=5 | VAM=0.75 | PCT\_AR=10 | BITOLA=0 | SENTIDO=Direto | TAXA\_IMG=1 | CAMINHO=saida.txt | FORMATO=texto
\[EXECUCAO] Iniciando simulação por 5 minuto(s)...
\[DISPLAY] 00000 m³ | 000 mm
\[SAIDA] Arquivo gerado em: saida.txt
\[DISPLAY] 00001 m³ | 349 mm
\[SAIDA] Arquivo gerado em: saida.txt
\[DISPLAY] 00002 m³ | 699 mm
\[SAIDA] Arquivo gerado em: saida.txt
\[DISPLAY] 00003 m³ | 374 mm
\[SAIDA] Arquivo gerado em: saida.txt
\[EXECUCAO] Simulação concluída.

```

Exemplo do arquivo `saida.txt`:
```

# Simulador de Hidrômetro Analógico

Leitura atual: 00003 m³ | 374 mm
Formato de saída: texto

````

---

## 🧭 Como executar (Windows / MinGW-w64)

### Pré-requisitos
- **g++** (MinGW-w64 / WinLibs) com C++17
- (opcional) VS Code

### Passos
1) Verifique o compilador:
```bash
g++ --version
````

2. Compile:

```bash
g++ -std=c++17 main.cpp Controlador.cpp Hidrometro.cpp Entrada.cpp Medicao.cpp Display.cpp Saida.cpp -o simulador.exe
```

> Se o Windows linkar como GUI e pedir `WinMain`, compile assim:

```bash
g++ -std=c++17 main.cpp Controlador.cpp Hidrometro.cpp Entrada.cpp Medicao.cpp Display.cpp Saida.cpp -o simulador.exe "-Wl,-subsystem,console"
```

3. Execute:

```bash
.\simulador.exe
```

---

## ⚙️ Configuração (arquivo `config.txt`)

Exemplo:

```
# Tempo total em minutos
TFS=5

# Vazão por minuto (m3/min)
VAM=0.75

# Percentual de ar (0..100)
PCT_AR=10

# Sentido do fluxo: Direto | Reverso
SENTIDO=Direto

# Gera saída a cada X m3
TAXA_IMG=1m3

# Caminho do arquivo de saída
CAMINHO=saida.txt

# Formato do display (nesta versão apenas "texto")
FORMATO=texto
```

**Parâmetros:**

* `TFS` – tempo total de simulação (minutos)
* `VAM` – vazão (interpretação: m³/min)
* `PCT_AR` – % de “passagem de ar” (desconto aplicado)
* `SENTIDO` – `Direto` conta; `Reverso` não contabiliza
* `TAXA_IMG` – periodicidade de geração por **volume** (ex.: `1m3`)
* `CAMINHO` – caminho/nome do arquivo de saída (v1: `.txt`)
* `FORMATO` – por ora informativo (`texto`)

---

## 🧩 Arquitetura (POO)

* **Controlador** – lê `config.txt` e orquestra a simulação.
* **Hidrometro** – coordena Entrada, Medicao, Display e Saida.
* **Entrada** – parâmetros do fluxo (vazão, sentido, ar%).
* **Medicao** – estado da leitura (m³ e mm) + lógica de odômetro.
* **Display** – exibe a leitura no terminal.
* **Saida** – persiste a leitura (v1: `.txt`; v2: `.jpg`).

> O **Diagrama de Classes (UML)** desta versão foi entregue em PDF separadamente (item 2 da avaliação).

---

## 📂 Estrutura do projeto

```
main.cpp
Controlador.hpp / Controlador.cpp
Hidrometro.hpp / Hidrometro.cpp
Entrada.hpp / Entrada.cpp
Medicao.hpp / Medicao.cpp
Display.hpp / Display.cpp
Saida.hpp / Saida.cpp
config.txt
```

---

## 🛣️ Roadmap (v2+)

* Geração **real** de imagem **JPEG** do mostrador:

  * renderizar mostrador com fundo branco, rótulos (m³ em preto; mm em vermelho),
  * sobrepor texto com leitura atual,
  * opções: usar **stb\_image\_write** (leve) ou **OpenCV** (completo).
* Ajustar `Display` para alternar entre `texto` e `jpeg`.
* Melhorar validação/erros do `config.txt`.

---

## 👤 Autoria

* Aluno(a): **SEU\_NOME**
* Disciplina: **Padrões de Projetos**
* Curso: **Engenharia de Computação**

> **Vídeo de demonstração (<= 40s):** *link será adicionado na próxima atualização.*

---

## 📄 Licença

Uso acadêmico/educacional.
(Se desejar, adicione uma licença formal – ex.: MIT – como `LICENSE` no repositório.)

```
```
