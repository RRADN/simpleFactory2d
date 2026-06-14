# 🎮 Roadmap - Simple Factory 2D Game Development

## Estado Actual del Proyecto
- ✅ **Core Setup**: CMake, SDL3 integrado
- ✅ **Estructura Base**: Game loop básico, ventana y renderer SDL3
- ✅ **Contexto SDL**: `src/platform/sdlContext.hpp` inicializa SDL
- ✅ **Window Management**: `src/platform/sdlWindow.hpp/cpp` crea la ventana y el renderer
- ✅ **Game Loop**: `src/game/simpleFactory.cpp` procesa eventos y renderiza pantalla en blanco
- ⚠️ **Assets**: carpeta de assets existe pero no hay contenido utilizable
- ⚠️ **Entity scaffolding**: archivos para `Entity` y `Tile` existen, pero están vacíos
- ❌ **Rendering de sprites/tilemap**: no implementado
- ❌ **Physics/colisiones**: no existe
- ❌ **Input avanzado**: solo se detecta evento de cierre de ventana
- ❌ **UI, audio, persistencia**: no implementados

## Objetivo inmediato
Terminar la base técnica mínima antes de avanzar a mecánicas de juego.

- [ ] Estabilizar el motor SDL3 y el ciclo principal
- [ ] Definir la estructura de entidades y la jerarquía base
- [ ] Implementar renderizado básico de pruebas
- [ ] Añadir movimiento y colisiones simples

---

## 📋 FASE 0: CONSOLIDAR LA BASE (Sprint 1)

### 0.1 Corrección de alcance
**Prioridad:** 🔴 CRÍTICA  
**Tiempo estimado:** 1 día

- [ ] Actualizar documentación para reflejar SDL3 en lugar de SFML
- [ ] Limpiar y verificar el `CMakeLists.txt`
- [ ] Confirmar que `src/platform/sdlContext.hpp` y `src/platform/sdlWindow.*` funcionan en Linux y Windows

### 0.2 Estructura de entidades mínima
**Prioridad:** 🔴 CRÍTICA  
**Tiempo estimado:** 2-3 días

- [ ] Implementar `Entity` base en `src/entities/primitive/entity.hpp/cpp`
- [ ] Definir `Tile` simple en `src/entities/primitive/tile.hpp/cpp`
- [ ] Crear `Player` básico en `src/entities/player/` con movimiento
- [ ] Añadir `Entity` y `Tile` al ciclo de juego para pruebas

### 0.3 Renderizado de prueba
**Prioridad:** 🔴 CRÍTICA  
**Dependencias:** 0.2  
**Tiempo estimado:** 2 días

- [ ] Renderizar un rectángulo o sprite de prueba en pantalla
- [ ] Añadir colores básicos y clear/present en el renderer
- [ ] Validar dimensiones y escalado de ventana

### 0.4 Input y loop de actualización
**Prioridad:** 🟡 ALTA  
**Dependencias:** 0.2  
**Tiempo estimado:** 1-2 días

- [ ] Capturar eventos de teclado en `Game::run`
- [ ] Mover una entidad `Player` con flechas/WASD
- [ ] Usar `deltaTime` para movimiento consistente
- [ ] Preparar base para futuros sistemas de input y animación

---

## 📦 FASE 1: CORE FUNCIONAL (Sprint 2-3)

### 1.1 Renderizado de mundo y tiles
**Prioridad:** 🔴 CRÍTICA  
**Tiempo estimado:** 3-4 días

- [ ] Implementar `TileMap` simple
  - [ ] Matriz de tiles en memoria
  - [ ] Renderizado de grid básico
  - [ ] Datos de tile sólidos/no sólidos
- [ ] Crear pipeline de assets
  - [ ] Texturas básicas de prueba
  - [ ] Ordenar `assets/` en `textures/`, `sprites/`, `sounds/`

### 1.2 Colisiones y movimiento sólido
**Prioridad:** 🔴 CRÍTICA  
**Dependencias:** 1.1  
**Tiempo estimado:** 2-3 días

- [ ] Definir cajas de colisión sencillas para `Entity`
- [ ] Detectar colisión con tiles sólidos
- [ ] Evitar que el player atraviese paredes
- [ ] Añadir modo debug para visualizar hitboxes

### 1.3 Separación de responsabilidades
**Prioridad:** 🟡 ALTA  
**Tiempo estimado:** 2 días

- [ ] Mover lógica de ventana y contexto fuera de `Game`
- [ ] Crear módulos de input, update y render
- [ ] Documentar la arquitectura de módulos en `README.md`

---

## 🎮 FASE 2: MECÁNICAS BÁSICAS (Sprint 4-5)

### 2.1 Animaciones y sprites
**Prioridad:** 🟡 ALTA  
**Tiempo estimado:** 3-4 días

- [ ] Sistema básico de animación por frames
- [ ] Animaciones de walking/idle
- [ ] Soporte para `spritesheet`

### 2.2 Cámara y viewport
**Prioridad:** 🟡 ALTA  
**Tiempo estimado:** 2 días

- [ ] Cámara que sigue al jugador
- [ ] Límites de mapa
- [ ] Zoom/viewport básico

### 2.3 NPCs e interacción inicial
**Prioridad:** 🟡 ALTA  
**Tiempo estimado:** 2-3 días

- [ ] Clase `NPC` y controlador de entidades
- [ ] Movimiento de patrulla simple
- [ ] Interacción de proximidad

---

## 🧱 FUTURO (Sprint 6+)

- [ ] UI de diálogo/inventario
- [ ] Guardado y carga de partida
- [ ] Audio y efectos
- [ ] Mecánicas de recolección/crafting
- [ ] Sistema de misión básica

---

## Notas importantes
- El proyecto actual está en una etapa de prototipo: el juego se inicia, pero solo presenta una ventana blanca y cierra correctamente.
- El progreso más valioso ahora es completar la base técnica antes de diseñar mecánicas complejas.
- El roadmap debe revisarse luego de implementar `Entity` y renderizado para ajustar prioridades.
