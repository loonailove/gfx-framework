# Card Games 🃏

```
src/lab_m1/Tema1/
|   # render si geometrie, ne ocupam exlusiv de primitivele OpenGL
├── core/
│   ├── Transform2D.h       # matricele de transformare 2D (Translate, Scale, Rotate)
|   ├── Object2D.cpp
│   └── Object2D.h          # generator de mesh-uri (dreptunghi, cerc, inima, simboluri)
|   # starea entitatilor
├── models/
│   ├── Card.h / .cpp       # clasa individuala pentru carti
│   ├── Deck.h / .cpp       # pentru gestionare stiva/pachet
│   └── Player.h / .cpp     # starea globala a jucatorului (Hand, BoardCards, HP, Mana)
|   # regulile jocului
├── logic/
|   ├── GameState.h
|   ├── GameManager.h
|   ├── GameManager.cpp
├── Tema1.cpp
└── Tema1.h