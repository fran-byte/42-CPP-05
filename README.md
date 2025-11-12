# 42-CPP-05

## Resumen de la logica de excepciones en ex00

# 🔹 Flujo completo de excepciones en `Bureaucrat` (C++98)

## 1️⃣ Definición de la excepción

Dentro de la clase `Bureaucrat` se define una **subclase de excepción** para manejar grados demasiado altos:

```cpp
class GradeTooHighException : public std::exception {
public:
    const char* what() const throw();
};
```

- `GradeTooHighException` hereda de `std::exception`.
- `what()` devuelve un **mensaje de error** (`const char*`).
- `const` → indica que el método no modifica el objeto.
- `throw()` → en C++98 garantiza que **este método no lanzará nuevas excepciones**, lo que es crucial porque `what()` normalmente se llama mientras ya hay otra excepción activa.

---

### 2️⃣ Implementación del método `what()` en el `.cpp`

```cpp
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}
```

- Devuelve un **mensaje de error fijo** que describe la condición.
- Este mensaje es lo que luego se imprimirá en el bloque `catch`.
- No lanza más excepciones gracias a `throw()`.

---

## 3️⃣ Lanzar la excepción

Cuando se detecta un error (por ejemplo, el grado del burócrata es demasiado alto):

```cpp
throw Bureaucrat::GradeTooHighException();
```

- Se **crea un objeto anónimo** (sin nombre) de la clase `GradeTooHighException`.
- Este objeto es lanzado como excepción y viaja hasta que se capture en un bloque `catch`.

---

## 4️⃣ Capturar la excepción

Se utiliza un bloque `try/catch` para manejar la excepción:

```cpp
try {
    Bureaucrat b("Juan", 0); // grado inválido
} catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

- `catch(std::exception &e)` → `e` es una **referencia al objeto anónimo** que se lanzó con `throw`.
- Esto permite **polimorfismo**, de manera que `e.what()` llama al método `what()` de la subclase real (`GradeTooHighException`) aunque el tipo del `catch` sea `std::exception&`.
- `e.what()` devuelve el **mensaje de error**, en este caso `"Grade too high"`.
- `std::cerr` lo imprime en la salida de errores.

**Salida esperada:**

```
Error: Grade too high
```

---

## 5️⃣ Rol de `what() const throw()`

- Garantiza que **no se lanzarán nuevas excepciones** desde `what()`.
- Devuelve **solo un mensaje de texto**, no el objeto de la excepción ni nada más complejo.
- Esto es fundamental en C++98 porque `what()` se llama normalmente cuando ya hay otra excepción activa.
- Si `what()` lanzara otra excepción, se rompería la promesa de `throw()` y se llamaría a `std::unexpected()`, lo que normalmente **terminaría el programa**.

---

## 6️⃣ Resumen completo del flujo

1. Se detecta un error (grado demasiado alto).
2. Se ejecuta:

```cpp
throw Bureaucrat::GradeTooHighException();
```

- Se crea un **objeto anónimo** de excepción y se lanza.

3. La excepción viaja hasta el bloque `catch` correspondiente:

```cpp
catch(std::exception &e)
```

- `e` es una **referencia** al objeto anónimo.

4. Se llama a:

```cpp
e.what()
```

- Devuelve el **mensaje de error** definido en la subclase.

5. El mensaje se imprime con `std::cerr`:

```
Error: Grade too high
```

---

### 7️⃣ Conceptos clave integrados

| Concepto                                      | Explicación                                                                                                                           |
| --------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| `throw GradeTooHighException();`              | Lanza una excepción de tipo `GradeTooHighException`. Crea un objeto anónimo.                                                          |
| `GradeTooHighException::what() const throw()` | Devuelve un mensaje de error y **no lanza nuevas excepciones**.                                                                       |
| `catch(std::exception &e)`                    | `e` es **referencia** al objeto anónimo lanzado; permite polimorfismo.                                                                |
| `e.what()`                                    | Devuelve el mensaje de error (`const char*`) del objeto real que se lanzó.                                                            |
| `throw()` en C++98                            | Es una **promesa**: si se rompe (es decir, si `what()` lanza algo), se llama a `std::unexpected()` y normalmente termina el programa. |
