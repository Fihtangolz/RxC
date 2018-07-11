# RxC
---
Good point to start Reactive programming is 
- [http://reactivex.io/]()
- [Reactive Design Patterns by Roland Kuhn]()

# Doc
---
- [Creating Observables]()
  - [create]()
  - [defer]()
  - [empty/never/throw ]()
  - [from]()
  - [interval ]()  
  - [just ]()
  - [range]()
  - [repeat ]()
  - [start]()
  - [timer]()
- [Transforming Observables]()
  - [buffer]()
  - [flatMap]()
  - [groupBy]()
  - [map]()  
  - [scan]()
  - [window]()
- [Filtering Observables]()
  - [debounce]()
  - [distinct]()
  - [elementAt]()
  - [filter]()
  - [first]()
  - [ignoreElements]()
  - [last]()
  - [sample]()
  - [skip]()
  - [skipLast]()
  - [take]()
  - [takeLast]()
- [Combining Observables]()
  - [And/Then/When]()
  - [combineLatest]()
  - [join]()
  - [merge]()
  - [startWith]()
  - [switch]()
  - [zip]()
- [Error Handling Operators]()
  - [catch]()
  - [retry]()
- [Observable Utility Operators]()
  - [delay]()
  - [do]()
  - [materialize/dematerialize]()
  - [observeOn]()
  - [serialize]()
  - [subscribe]()
  - [subscribeOn]()
  - [timeInterval]()
  - [timeout]()
  - [timestamp]()
  - [using]()
- [Conditional and Boolean Operators]()
  - [all]()
  - [amb]()
  - [contains]()
  - [defaultIfEmpty]()
  - [sequenceEqual]()
  - [skipUntil]()
  - [skipWhile]()
  - [takeUntil]()
  - [takeWhile]()
- [Mathematical and Aggregate Operators]()
  - [average]()
  - [concat]()
  - [count]()
  - [max]()
  - [min]()
  - [reduce]()
  - [sum]()
- [Backpressure Operators]()
  - []()
- [Connectable Observable Operators]()
  - [connect]()
  - [publish]()
  - [refCount]()
  - [replay]()
- [Operators to Convert Observables]()
  - [To]()

# Observer

Observers are simple objects that receive values from Observables.

---

#### `.create(onNext, onError, onCompleted)`

Creates a new Observer.

| Name | Type | Default | Description |
|------|------|---------|-------------|
| `onNext` | function (optional) |  | Called when the Observable produces a value. |
| `onError` | function (optional) |  | Called when the Observable terminates due to an error. |
| `onCompleted` | function (optional) |  | Called when the Observable completes normally. |

---
