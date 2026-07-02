## 📖 Agenda Telefônica em C

> Um sistema interativo de gerenciamento de contatos desenvolvido em C. O projeto utiliza Listas Encadeadas Simples e alocação dinâmica de memória para manter os registros organizados de forma eficiente e ordenados alfabeticamente.

---

### 🚀 Funcionalidades

* **Adicionar Contato:** Insere um novo registro de forma dinâmica, garantindo que a lista permaneça em ordem alfabética.
* **Listar Contatos:** Percorre a lista e exibe todos os contatos salvos na memória.
* **Buscar Contato:** Realiza a busca detalhada através do nome exato do usuário.
* **Editar Contato:** Permite a atualização rápida de telefone e e-mail sem quebrar a ordenação da lista.
* **Excluir Contato:** Remove o nó específico da memória e ajusta os ponteiros da lista encadeada.

---

### 🛠️ Tecnologias e Conceitos Utilizados

* Linguagem C
* Estruturas de Dados (Listas Encadeadas)
* Alocação Dinâmica de Memória (`malloc`, `free`)
* Modularização de Código (`.h` e `.c`)
* Manipulação de Strings e Limpeza de Buffer

---

### 📂 Estrutura do Projeto

* `agenda.h`: Arquivo de cabeçalho contendo a definição das `structs` (`CONTATO` e `AGENDA`) e as assinaturas de todas as funções do sistema.
* `agenda.c`: Arquivo com a implementação da lógica das operações da lista encadeada.
* `main.c`: Arquivo principal contendo o menu interativo e a comunicação com o usuário via terminal.

---

### 💻 Como Executar

1. Clone este repositório ou faça o download dos arquivos em uma mesma pasta.
2. Abra o terminal e navegue até o diretório do projeto.
3. Compile os arquivos e execute o programa gerado:
   ```bash
   gcc main.c agenda.c -o agenda
   ./agenda
