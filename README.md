# Technical Framework: Player Protection - The Black Box of Logic

The framework titled **"Player Protection: The Black Box of Logic"** establishes a secure-by-design architecture that shifts the authority of game logic and data validation from the player's client device to a controlled serverless environment. Historically, the video game industry—particularly in independent and academic sectors—has relied on client-side validation, which creates structural vulnerabilities such as score manipulation, account theft, and the distribution of unauthorized versions. This project addresses these gaps by applying **distributed computing principles** and a **Zero Trust paradigm**, ensuring that every request is authenticated, authorized, and verified regardless of its origin.

### Technological Implementation and Usage
The system is constructed using an **Amazon Web Services (AWS)** serverless stack, which reduces the attack surface by eliminating permanently exposed server infrastructure. The operational flow is managed through several key layers:

*   **Identity and Perimeter Security:** **Amazon Cognito** manages player identities and issues digitally signed **JSON Web Tokens (JWT)**. **Amazon API Gateway** acts as the secure entry point, performing initial token validation and enforcing rate limiting (throttling) to prevent brute-force attacks and resource abuse.
*   **Business Logic and Validation:** **AWS Lambda** functions execute the core game logic on demand. For instance, the `VerifyPlayerStats` flow ensures data integrity by recalculating **HMAC-SHA256 signatures** on the server side to detect if the client has tampered with game metrics. Similarly, the `VerifyGameHash` function checks the integrity of the game's executable against a table of authorized versions in **Amazon DynamoDB**.
*   **Data Consistency and Distribution:** **Amazon DynamoDB** provides high-performance, NoSQL storage for player profiles and session states, utilizing **TTL (Time To Live)** attributes to automatically purge expired tokens and temporary data. For the secure distribution of assets, the system uses **Amazon S3** with **presigned URLs**, granting players temporary, five-minute access to specific files without exposing the storage bucket publicly.
*   **Observability:** **Amazon CloudWatch** centralizes logging and monitoring, enabling the detection of anomalous patterns, such as repeated failed login attempts or unusual traffic, which can trigger automated defensive responses like account suspension or IP blocking.

### Authorship and Direction
This Final Degree Project (TFG) was developed at the **Universidad Complutense de Madrid** by authors **Alberto Peñalba Martos** and **Dorje Khampa Herrezuelo Blasco**, under the direction of **José Luis Vázquez Poletti** and **David Pacios Izquierdo**.
---

# Korrekturen die wir vornehmen müssen
Estado de la cuestión: Añadir un cierre comparativo claro entre DRM, anti-cheat centrado en cliente, validación server-side y observabilidad, para que el capítulo no quede solo como un recorrido descriptivo.
Más citas académicas y menos webs secundarias.
Introducir, si te encaja, una síntesis final de criterios de elección: qué resuelve cada enfoque, qué no resuelve y por qué tu arquitectura se coloca donde se coloca.

Tecnologías utilizadas: hablar menos de AWS y de sus servicios en general y dejar más centrada la exposición en las decisiones que realmente utiliza el prototipo.
Borrar y releer lo que queda de capítulo (IAC).

Arquitectura y diseño: Revisar figuras a lo mejor hay que explicarlas más.

Conclusiones y final: ¿poner links a los casos que se mencionan?

Bibliografía: cita 14 (está en la página 43)
corregir entradas (title, links obsoletos, bibliografía sin citar)
menos webs más artículos académicos

Anexo: JSON schemas


La revisión final debería hacerse también con foco en grafías oficiales de herramientas y servicios, porque aquí un detalle pequeño sí da imagen de falta de pulido.
Revisar acrónimos y definir si no están.
Simplificar sintáxis. (principalmente cap3)
Leyendas en los gráficos
Una vez hecho el cap 5 bien mirar si el 6 se puede apoyar más en este
Revisar cursivas.

---
# Lista de correcciones — Memoria TFG

---

## 🔴 PRIORIDAD 1 — Hacer primero

### Limpiar notas internas y comentarios
- [X] Eliminar `// HABRÍA QUE MENCIONAR EN ESTE CAPÍTULO MÁS SOBRE EL IaC...` (pág. 30)
- [X] Eliminar `(Dar una vuelta a este párrafo)` y reescribir el párrafo afectado (pág. 30)
- [X] Eliminar `// esto hay que quitar porque se soluciona en la sección 4.1` (pág. 35)
- [X] Eliminar TODO el bloque `"Como abordaría este capítulo..."` (pág. 43)
- [X] Eliminar la respuesta del tutor `"Respuesta de Poletti: La idea es que..."` (pág. 43)
- [ ] Revisar el documento completo en busca de cualquier otra nota interna o comentario de edición que haya quedado 

### Política bilingüe
- [X] Decidir si el documento es en español o bilingüe
- [X] Si bilingüe: completar las partes en inglés que están vacías o sin simetría con el español
- [X] Si solo español: retirar las secciones en inglés incompletas

### Clave secreta embebida en el cliente Unity (pág. 35)
- [X] Replantear el mecanismo de la clave secreta embebida mediante ofuscación — contradice el principio de trasladar la autoridad al servidor
- [X] Sustituir por una alternativa coherente: validación server-side, tokens efímeros, nonces, firma asimétrica u otra solución que no dependa de un secreto residente en el cliente
23/04/2026
---

## 🟠 PRIORIDAD 2 — Capítulo 5 (Casos de uso)

- [X] Reescribir completamente la apertura del capítulo para que empiece como texto final de memoria, no como planificación interna (pág. 43)
- [ ] Estructurar cada caso de uso con estas cuatro piezas claramente separadas:
  - [ ] Escenario
  - [ ] Ejecución
  - [ ] Evidencia observada
  - [ ] Interpretación
- [ ] Añadir resultados concretos: logs, eventos, códigos de respuesta, trazas en CloudWatch, ejemplos de rechazo, cambios de estado o capturas representativas
- [ ] Añadir una síntesis final del capítulo que muestre qué ha quedado validado y con qué límites
- [ ] Garantizar que la validación es observacional, bien documentada, con pruebas reproducibles y evidencia trazable

---

## 🟠 PRIORIDAD 2 — Conclusiones (pág. 49–50)

- [X] Cambiar `"infalible"` por `"pilar clave"` o `"componente central"` en el apartado de observabilidad
- [X] Sustituir `"evidencias irrefutables"` por `"evidencias auditables"` o `"trazas verificables"`
- [X] Reformular `"la pérdida de todo su progreso como castigo"` en términos técnicos: revocación, invalidación, medida automática ante manipulación detectada
- [X] Sustituir `"de manera eficiente, sencilla, gratis o a bajo coste"` por `"con un coste operativo reducido"` (pág. 50)

- [X] Ampliar el trabajo futuro con líneas concretas: carga, latencia, coste, mejora del cliente, refuerzo de observabilidad, automatización, reproducibilidad, ampliación del modelo de pruebas
- [X] Mejorar la maquetación de la página 50 para que el cierre no quede visualmente pobre


- [X] Hacer que cada conclusión importante remita explícitamente a un resultado observado en el capítulo 5
---

## 🟡 PRIORIDAD 3 — Revisiones por capítulo

### Introducción
- [X] Revisar las frases que apoyan una afirmación fuerte en un caso muy reciente o periodístico (pág. 5)
- [X] Reformular `"Sin ir más lejos en febrero de 2026..."` con un arranque más neutro, por ejemplo: *"Como ejemplo reciente..."* o *"Un caso documentado recientemente..."* (pág. 5)

### Estado de la cuestión
- [ ] Añadir un cierre comparativo claro entre DRM, anti-cheat centrado en cliente, validación server-side y observabilidad
- [ ] Reforzar el aparato bibliográfico con más artículos, estándares y literatura académica (reducir dependencia de documentación de fabricante y recursos web secundarios)
- [ ] Añadir una síntesis final de criterios de elección: qué resuelve cada enfoque, qué no resuelve, y por qué la arquitectura del trabajo se sitúa donde se sitúa

### Tecnologías utilizadas
- [ ] Recortar las partes que solo describen servicios de AWS de forma general; centrar la exposición en las decisiones reales del prototipo
- [X] Revisar el apartado `"3.4.2. Validación de licencias"` (pág. 22): renombrarlo para reflejar que trata el alta del usuario y la gestión de identidad, o bien completar el flujo real de validación de licencias
- [ ] Eliminar las notas internas de trabajo pendiente (ya cubiertas en prioridad 1, verificar también en este capítulo)
- [ ] Definir todos los acrónimos en su primera aparición — eliminar recordatorios de edición incrustados
- [ ] Reescribir frases infladas o redundantes para simplificar la sintaxis técnica
- [ ] Si se menciona IaC como parte de la reproducibilidad, integrarlo en el cuerpo de forma académica o llevarlo a un anexo; no dejarlo como idea colgando (pág. 30)
- [X] Corregir `"Se emplea para tareas como para generar licencias..."` → `"Se emplea para tareas como generar licencias..."` (pág. 16)
- [X] Reescribir la frase que repite dos veces la idea de escalabilidad de AWS Lambda (pág. 16)
- [X] Reescribir `"Por esto, es preferente ante Aurora en este escenario. Siendo una solución serverless..."` como una sola frase bien cerrada (pág. 17)
- [X] Matizar o suprimir `"Por estas razones, grandes estudios y títulos AAA aprovechan S3 y su ecosistema..."` — si no se apoya con ejemplos concretos, recortar (pág. 17)

### Arquitectura y diseño
- [ ] Eliminar cualquier comentario interno que haya quedado en el capítulo
- [ ] Explicar mejor cada figura dentro del texto: qué muestra, qué estados son relevantes, qué decisiones del sistema representa
- [X] Explicar explícitamente el estado `"FORCE CLOUD"`: qué condición lo activa, qué significa, qué hace Unity al recibirlo (pág. 37)
- [X] Reescribir `"Unity no es un cliente impenetrable a día de hoy es de los clientes más accesibles para desarrolladores pero de los más inseguros."` — separar las ideas, eliminar afirmaciones absolutas o apoyarlas documentalmente (pág. 42)

---

## 🔵 PRIORIDAD 4 — Pasada de estilo y uniformidad

### Erratas y nombres propios
- [X] Corregir `"BattelEye"` → `"BattlEye"` (pág. 5)
- [X] Corregir `"includo"` → `"incluso"` (pág. 18)
- [X] Uniformar `"Amazon Cloudwatch"` / `"Cloudwatch"` / `"cloudwatch"` → `"Amazon CloudWatch"` / `"CloudWatch"` en todo el documento (págs. 18, 42 y cualquier otra aparición)
- [X] Corregir `"Des esta forma Cloudwatch..."` → `"De esta forma, CloudWatch..."` (pág. 18)
- [X] Expandir `"RPS"` en su primera aparición: `"RPS (Requests Per Second)"` — eliminar la nota `"(Explicar siglas arriba)"` (pág. 25)
- [ ] Revisar todas las siglas del documento y expandirlas en su primera aparición

### Tono y estilo
- [ ] Eliminar arranques conversacionales u orales en el cuerpo del texto
- [ ] Rebajar todas las palabras absolutas: *infalible, irrefutable, ideal, gratis, castigo* y similares
- [ ] En párrafos largos: simplificar la sintaxis y eliminar repeticiones de una misma idea dentro de la misma frase
- [ ] Sustituir formulaciones moralizantes o demasiado enfáticas por lenguaje técnico sobrio

---

## 📚 Bibliografía

- [X] Corregir entradas mal formadas — especialmente las que dejan visible texto tipo `"Title:"` o URLs mal integradas
- [ ] Verificar la trazabilidad de todas las citas: que no haya referencias sin citar ni citas sin entrada bibliográfica
- [ ] Priorizar artículos, normas, documentación oficial y literatura académica para sostener el estado del arte y las afirmaciones metodológicas
- [ ] Mover blogs, noticias y tutoriales sin autoría clara a notas a pie de página; no usarlos como base principal del aparato crítico

---

## 📎 Anexos (opcionales pero recomendados)

- [X] Añadir anexo con ejemplos de logs o eventos observados en CloudWatch
- [ ] Valorar añadir un anexo breve con JSON schemas, endpoints principales o tablas de DynamoDB resumidas
- [ ] Mover a anexo cualquier material técnico que da contexto y evidencia pero recargaría el cuerpo principal

---

## ✅ Checklist de cierre final

- [ ] No quedan notas internas ni comentarios del tutor en ninguna página
- [ ] Todas las siglas están expandidas en su primera aparición
- [X] `CloudWatch`, `BattlEye` y demás nombres técnicos son uniformes en todo el documento
- [X] No hay palabras absolutas sin respaldo documental (*infalible, irrefutable*, etc.)
- [ ] Todas las figuras tienen explicación en el texto (no solo están insertadas)
- [ ] El capítulo 5 contiene evidencia observada real y una síntesis de validación
- [ ] Las conclusiones remiten explícitamente a resultados del capítulo 5
- [ ] La bibliografía está limpia, bien formada y trazable
- [ ] La página 50 no queda visualmente ni argumentalmente pobre
