# Simulador-de-Hidrometro-Analogico
Projeto acadêmico desenvolvido em C++ com Programação Orientada a Objetos para simular o funcionamento de um hidrômetro analógico.  
Esta é a **primeira versão**: a saída é exibida no terminal e salva em um arquivo texto (`saida.txt`).  
Na próxima versão, será implementada a geração de imagem (`.jpeg`) do mostrador do hidrômetro.

## Objetivo
- Simular o comportamento de um hidrômetro analógico em software.  
- Permitir configurar parâmetros como vazão, sentido do fluxo e percentual de ar.  
- Exibir leituras em tempo real no terminal.  
- Registrar as leituras em arquivo texto.  
- Servir como base para futura evolução para saída gráfica em imagem JPEG.

## Tecnologias Utilizadas
- **C++17** com Programação Orientada a Objetos (POO).  
- **VS Code** como ambiente de desenvolvimento.  
- **MinGW-w64 (g++)** como compilador.  
- Saída atual em **terminal** e **arquivo texto** (`saida.txt`).  
- Futuramente: geração de imagem com **stb_image_write** ou **OpenCV**.  

## Colaboradores
Este projeto foi desenvolvido por:

- [Maria Clara Colaço](https://github.com/claracolaco)

## Como Executar o Projeto
1. Clone este repositório.  
2. Garanta que possui o compilador **g++** instalado (MinGW-w64 / WinLibs).  
3. Compile todos os arquivos `.cpp`:
```bash
g++ -std=c++17 main.cpp Controlador.cpp Hidrometro.cpp Entrada.cpp Medicao.cpp Display.cpp Saida.cpp -o simulador.exe 
```
Se o Windows pedir WinMain, compile assim:
```bash
g++ -std=c++17 main.cpp Controlador.cpp Hidrometro.cpp Entrada.cpp Medicao.cpp Display.cpp Saida.cpp -o simulador.exe "-Wl,-subsystem,console"
```
4. Execute:
```bash
.\simulador.exe
```

## Observações
- O terminal mostra as leituras minuto a minuto, por exemplo:
```bash
[DISPLAY] 00002 m³ | 675 mm
[SAIDA] Arquivo gerado em: saida.txt
```
- O arquivo saida.txt registra a última leitura:
```bash
Simulador de Hidrômetro Analógico
===============================
Leitura atual: 00003 m³ | 374 mm
Formato de saída: texto
```
- Os parâmetros da simulação são definidos no arquivo config.txt:
```bash
TFS=5
VAM=0.75
PCT_AR=10
SENTIDO=Direto
TAXA_IMG=1m3
CAMINHO=saida.txt
FORMATO=texto
```
## Estrutura do Repositório
- main.cpp → ponto de entrada do programa.
- Controlador.* → lê o arquivo de configuração e orquestra a simulação.
- Hidrometro.* → integra Entrada, Medicao, Display e Saida.
- Entrada.* → controla os parâmetros de fluxo (vazão, sentido, ar%).
- Medicao.* → registra o volume total e controla o odômetro.
- Display.* → exibe a leitura atual no terminal.
- Saida.* → gera o arquivo saida.txt com a leitura.
- config.txt → arquivo de configuração da simulação.
