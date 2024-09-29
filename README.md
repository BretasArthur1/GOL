Aqui está o README atualizado com uma explicação sobre o padrão **MVC (Model-View-Controller)**:

---

# Jogo da Vida de Conway

Este projeto implementa o famoso **Jogo da Vida de Conway** em C++, utilizando o padrão **MVC (Model-View-Controller)**. O jogo simula o comportamento de células vivas e mortas em uma grade bidimensional, seguindo regras simples de reprodução, morte e sobrevivência.

## 📊 Sumário

1. [Descrição](#descrição)
2. [Padrão MVC](#padrão-mvc)
3. [Tecnologias Utilizadas](#tecnologias-utilizadas)
4. [Estrutura do Projeto](#estrutura-do-projeto)
5. [Como Executar](#como-executar)
6. [Resultados](#resultados)
7. [Contribuições](#contribuições)
8. [Licença](#licença)
9. [Contato](#contato)

## 📝 Descrição

O **Jogo da Vida** é um autômato celular desenvolvido pelo matemático John Conway, onde células em uma grade bidimensional seguem regras de interação com seus vizinhos para determinar se vivem, morrem ou se reproduzem. Este projeto implementa o jogo em C++ utilizando o padrão **MVC (Model-View-Controller)**, o que facilita a separação de responsabilidades no código e melhora sua manutenção e escalabilidade.

### Objetivos Principais

- **Simulação do Jogo da Vida:** Implementação das regras básicas de interação celular.
- **Arquitetura MVC:** Separação clara entre a lógica do jogo (modelo), a interface de visualização (visão) e o controle das interações (controlador).
- **Interação do Usuário:** Controle das gerações e iterações através do terminal.
- **Interface Modular:** Permitir fácil manutenção e extensão do código.

## 🎯 Padrão MVC

O padrão **MVC (Model-View-Controller)** foi adotado para organizar o código de forma eficiente e modular:

- **Modelo (Model):** Responsável por toda a lógica e regras do jogo, armazenando o estado atual da simulação. No caso do Jogo da Vida, o modelo cuida do estado da grade e das regras que determinam o comportamento das células.
- **Visão (View):** Cuida da interface de visualização, exibindo o estado atual da simulação ao usuário. A visão não lida com a lógica do jogo, apenas com a exibição da informação.
- **Controlador (Controller):** Atua como um intermediário entre o modelo e a visão. Ele recebe entradas do usuário (como iniciar ou parar a simulação), atualiza o modelo de acordo com essas entradas e então notifica a visão para que a tela seja atualizada.

Essa estrutura permite que cada parte do código tenha uma responsabilidade única, tornando mais fácil a manutenção e a expansão do projeto.

## 🛠 Tecnologias Utilizadas

- **Linguagem de Programação:** C++
- **Compilador:** g++ ou equivalente

## 📂 Estrutura do Projeto

```plaintext
conway_game_of_life/
│
├── JV_PJA_Main.cpp       # Ponto de entrada do programa
├── JV_PJA_Controller.cpp # Controlador da aplicação
├── JV_PJA_Controller.h   
├── JV_PJA_Model.cpp      # Lógica do jogo e estado da grade
├── JV_PJA_Model.h
├── JV_PJA_View.cpp       # Responsável por exibir o estado do jogo
├── JV_PJA_View.h
├── README.md             # Documentação do projeto
└── LICENSE               # Informações sobre a licença do projeto
```

- **JV_PJA_Main.cpp:** Contém a função principal que inicializa o jogo.
- **JV_PJA_Controller.cpp e JV_PJA_Controller.h:** Controla a lógica de interação entre o usuário e a simulação, chamando os métodos do modelo e atualizando a visão.
- **JV_PJA_Model.cpp e JV_PJA_Model.h:** Implementa as regras e a lógica do jogo, gerenciando o estado das células e a atualização da grade.
- **JV_PJA_View.cpp e JV_PJA_View.h:** Responsável por exibir a grade e o estado das células na tela, sem modificar a lógica do jogo.

## 🚀 Como Executar

### 1. Clone o Repositório

```bash
git clone https://github.com/BretasArthur1/conway_game_of_life
cd conway_game_of_life
```

### 2. Compile o Projeto

```bash
g++ -o JogoDaVida JV_PJA_Main.cpp JV_PJA_Controller.cpp JV_PJA_Model.cpp JV_PJA_View.cpp
```

### 3. Execute o Programa

```bash
./JogoDaVida
```

O programa será executado no terminal, onde você poderá visualizar a evolução das células na grade a cada iteração.

## 🏆 Resultados

Este projeto implementa corretamente as regras do Jogo da Vida, mostrando uma simulação dinâmica das gerações de células. A simulação termina automaticamente ou pode ser parada manualmente pelo usuário. 

## 🤝 Contribuições

Contribuições são bem-vindas! Se você encontrar algum bug ou quiser sugerir melhorias, fique à vontade para abrir issues ou enviar pull requests.

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 📫 Contato

Para dúvidas ou sugestões, entre em contato:

- **Email:** arthurbretas1@gmail.com
- **LinkedIn:** [Meu LinkedIn](https://www.linkedin.com/in/arthur-bretas-b2a6a82b9/)
- **GitHub:** [Meu GitHub](https://github.com/BretasArthur1)

---

Este README agora inclui uma explicação clara sobre o padrão MVC e como ele foi aplicado no projeto. Você pode ajustar os detalhes conforme necessário!
